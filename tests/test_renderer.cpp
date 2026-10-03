#include "renderer.h"

#include <gtest/gtest.h>
#include <memory>
#include <stdexcept>
#include <type_traits>

// A renderer owns an SDL resource, so copying it must stay disabled.
static_assert(!std::is_copy_constructible_v<Renderer>);
static_assert(!std::is_copy_assignable_v<Renderer>);

namespace {

using SurfacePtr = std::unique_ptr<SDL_Surface, decltype(&SDL_DestroySurface)>;

class RendererTest : public ::testing::Test {
  protected:
    SDL_Window* window = nullptr;

    void SetUp() override {
        // Software rendering makes pixel comparisons independent of the GPU.
        ASSERT_TRUE(SDL_SetHintWithPriority(SDL_HINT_RENDER_DRIVER, "software", SDL_HINT_OVERRIDE));
        ASSERT_TRUE(SDL_Init(SDL_INIT_VIDEO)) << SDL_GetError();
        window = SDL_CreateWindow("Renderer tests", 64, 64, SDL_WINDOW_HIDDEN);
        ASSERT_NE(window, nullptr) << SDL_GetError();
    }

    void TearDown() override {
        // Local Renderer objects are destroyed before this releases the window.
        SDL_DestroyWindow(window);
        SDL_Quit();
        SDL_ResetHint(SDL_HINT_RENDER_DRIVER);
    }

    SurfacePtr ReadPixels() {
        // Read before Present(): the backbuffer is not preserved after presenting.
        return SurfacePtr(SDL_RenderReadPixels(SDL_GetRenderer(window), nullptr),
                          SDL_DestroySurface);
    }

    void ExpectPixel(SDL_Surface* surface, int x, int y, const Color& expected) {
        SCOPED_TRACE(::testing::Message() << "Pixel (" << x << ", " << y << ")");
        Uint8 red = 0;
        Uint8 green = 0;
        Uint8 blue = 0;
        Uint8 alpha = 0;
        ASSERT_TRUE(SDL_ReadSurfacePixel(surface, x, y, &red, &green, &blue, &alpha))
            << SDL_GetError();
        EXPECT_EQ(red, expected.red);
        EXPECT_EQ(green, expected.green);
        EXPECT_EQ(blue, expected.blue);
        EXPECT_EQ(alpha, expected.alpha);
    }
};

TEST_F(RendererTest, CreatesRendererForValidWindow) {
    EXPECT_EQ(SDL_GetRenderer(window), nullptr);
    ASSERT_NO_THROW({
        Renderer renderer(window);
        EXPECT_NE(SDL_GetRenderer(window), nullptr);
    });
}

TEST_F(RendererTest, RejectsNullWindow) {
    EXPECT_THROW(Renderer renderer(nullptr), std::runtime_error);
}

TEST_F(RendererTest, ReleasesRendererWhenItGoesOutOfScope) {
    {
        Renderer renderer(window);
        ASSERT_NE(SDL_GetRenderer(window), nullptr);
    }
    EXPECT_EQ(SDL_GetRenderer(window), nullptr);

    // The window remains usable, and another renderer can be created for it.
    EXPECT_NO_THROW(Renderer replacement(window));
}

TEST_F(RendererTest, ClearScreenFillsEntireDrawingAreaWithRequestedColor) {
    Renderer renderer(window);
    const Color background{17, 83, 149, 255};
    renderer.ClearScreen(background);

    auto pixels = ReadPixels();
    ASSERT_NE(pixels, nullptr) << SDL_GetError();
    for (int y = 0; y < pixels->h; ++y) {
        for (int x = 0; x < pixels->w; ++x) {
            ExpectPixel(pixels.get(), x, y, background);
        }
    }
}

TEST_F(RendererTest, DrawFilledRectUsesRequestedColorPositionAndSize) {
    Renderer renderer(window);
    const Color background{0, 0, 0, 255};
    const Color rectangle{255, 0, 0, 255};
    renderer.ClearScreen(background);
    // Distinct coordinates and dimensions catch swapped x/y or width/height.
    renderer.DrawFilledRect(rectangle, Bounds{7.0f, 13.0f, 19.0f, 11.0f});

    auto pixels = ReadPixels();
    ASSERT_NE(pixels, nullptr) << SDL_GetError();
    for (int y = 0; y < pixels->h; ++y) {
        for (int x = 0; x < pixels->w; ++x) {
            const bool inside = x >= 7 && x < 26 && y >= 13 && y < 24;
            ExpectPixel(pixels.get(), x, y, inside ? rectangle : background);
        }
    }
}

TEST_F(RendererTest, ClearScreenRemovesPreviouslyDrawnContent) {
    Renderer renderer(window);
    renderer.ClearScreen(Color{0, 0, 0, 255});
    renderer.DrawFilledRect(Color{255, 0, 0, 255}, Bounds{7.0f, 13.0f, 19.0f, 11.0f});
    const Color nextBackground{31, 97, 163, 255};
    renderer.ClearScreen(nextBackground);

    auto pixels = ReadPixels();
    ASSERT_NE(pixels, nullptr) << SDL_GetError();
    for (int y = 0; y < pixels->h; ++y) {
        for (int x = 0; x < pixels->w; ++x) {
            ExpectPixel(pixels.get(), x, y, nextBackground);
        }
    }
}

TEST_F(RendererTest, LaterRectangleOverwritesOverlapAndPreservesOtherPixels) {
    Renderer renderer(window);
    const Color black{0, 0, 0, 255};
    const Color red{255, 0, 0, 255};
    const Color blue{0, 0, 255, 255};
    renderer.ClearScreen(black);
    renderer.DrawFilledRect(red, Bounds{5.0f, 8.0f, 20.0f, 16.0f});
    renderer.DrawFilledRect(blue, Bounds{15.0f, 18.0f, 22.0f, 12.0f});

    auto pixels = ReadPixels();
    ASSERT_NE(pixels, nullptr) << SDL_GetError();
    for (int y = 0; y < pixels->h; ++y) {
        for (int x = 0; x < pixels->w; ++x) {
            const bool inRed = x >= 5 && x < 25 && y >= 8 && y < 24;
            const bool inBlue = x >= 15 && x < 37 && y >= 18 && y < 30;
            const Color& expected = inBlue ? blue : (inRed ? red : black);
            ExpectPixel(pixels.get(), x, y, expected);
        }
    }
}

} // namespace
