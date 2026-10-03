#include "platform.h"

#include <SDL3/SDL.h>
#include <gtest/gtest.h>
#include <memory>

namespace {

class PlatformTest : public ::testing::Test {
  protected:
    void SetUp() override {
        shutdownPlatform();
        ConfigureDrivers();
    }

    void TearDown() override {
        // Runs even when a test assertion fails partway through initialization.
        shutdownPlatform();
        SDL_ResetHint(SDL_HINT_AUDIO_DRIVER);
        SDL_ResetHint(SDL_HINT_RENDER_DRIVER);
        SDL_ResetHint(SDL_HINT_VIDEO_DRIVER);
    }

    void ConfigureDrivers() {
        // CI has no speakers; drawing tests do not need a physical GPU either.
        ASSERT_TRUE(SDL_SetHintWithPriority(SDL_HINT_AUDIO_DRIVER, "dummy", SDL_HINT_OVERRIDE));
        ASSERT_TRUE(SDL_SetHintWithPriority(SDL_HINT_RENDER_DRIVER, "software", SDL_HINT_OVERRIDE));
    }
};

TEST_F(PlatformTest, InitializesVideoAudioWindowAndRenderer) {
    ASSERT_TRUE(initializePlatform()) << SDL_GetError();
    EXPECT_EQ(SDL_WasInit(SDL_INIT_VIDEO | SDL_INIT_AUDIO), SDL_INIT_VIDEO | SDL_INIT_AUDIO);

    int count = 0;
    std::unique_ptr<SDL_Window*, decltype(&SDL_free)> windows(SDL_GetWindows(&count), SDL_free);
    ASSERT_NE(windows, nullptr) << SDL_GetError();
    ASSERT_EQ(count, 1);
    EXPECT_NE(SDL_GetRenderer(windows.get()[0]), nullptr);

    // This is a smoke check for the platform's drawing/present path.
    // Exact drawing results are asserted in test_renderer.cpp before Present().
    renderPlatform();
    shutdownPlatform();
    EXPECT_EQ(SDL_WasInit(0), 0u);
}

TEST_F(PlatformTest, ShutdownIsSafeBeforeInitialization) {
    shutdownPlatform();
    EXPECT_EQ(SDL_WasInit(0), 0u);
}

TEST_F(PlatformTest, ShutdownIsSafeWhenCalledTwice) {
    ASSERT_TRUE(initializePlatform()) << SDL_GetError();
    shutdownPlatform();
    shutdownPlatform();
    EXPECT_EQ(SDL_WasInit(0), 0u);
}

TEST_F(PlatformTest, CanInitializeAgainAfterShutdown) {
    ASSERT_TRUE(initializePlatform()) << SDL_GetError();
    shutdownPlatform();
    EXPECT_EQ(SDL_WasInit(0), 0u);

    ConfigureDrivers();
    ASSERT_TRUE(initializePlatform()) << SDL_GetError();
    shutdownPlatform();
    EXPECT_EQ(SDL_WasInit(0), 0u);
}

TEST_F(PlatformTest, RenderWithoutInitializationReturnsSafely) {
    renderPlatform();
    EXPECT_EQ(SDL_WasInit(0), 0u);
}

TEST_F(PlatformTest, VideoInitializationFailureReturnsFalseAndAllowsShutdown) {
    ASSERT_TRUE(
        SDL_SetHintWithPriority(SDL_HINT_VIDEO_DRIVER, "missing-test-driver", SDL_HINT_OVERRIDE));
    EXPECT_FALSE(initializePlatform());
    shutdownPlatform();
    EXPECT_EQ(SDL_WasInit(0), 0u);
}

TEST_F(PlatformTest, WindowCreationFailureCleansUpInitializedSubsystems) {
    // SDL's dummy video backend cannot create the OpenGL window used by the platform.
    ASSERT_TRUE(SDL_SetHintWithPriority(SDL_HINT_VIDEO_DRIVER, "dummy", SDL_HINT_OVERRIDE));
    EXPECT_FALSE(initializePlatform());
    // Check cleanup BEFORE calling shutdown, so missing failure-path cleanup is caught.
    EXPECT_EQ(SDL_WasInit(0), 0u);
    shutdownPlatform();
    EXPECT_EQ(SDL_WasInit(0), 0u);
}

TEST_F(PlatformTest, RendererCreationFailureCleansUpWindowAndSubsystems) {
    ASSERT_TRUE(SDL_SetHintWithPriority(SDL_HINT_RENDER_DRIVER, "missing-test-renderer",
                                        SDL_HINT_OVERRIDE));
    EXPECT_FALSE(initializePlatform());
    EXPECT_EQ(SDL_WasInit(0), 0u);
    // Catches a dangling window pointer left behind by the failure path.
    shutdownPlatform();
    EXPECT_EQ(SDL_WasInit(0), 0u);

    // Startup can recover once the failing renderer setting is removed.
    ConfigureDrivers();
    ASSERT_TRUE(initializePlatform()) << SDL_GetError();
}

} // namespace
