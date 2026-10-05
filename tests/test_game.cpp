#include "game.h"
#include "input.h"
#include "render_api.h"

#include <gtest/gtest.h>

#include <set>
#include <vector>

namespace {

struct DrawCall {
    Color color;
    Bounds bounds;
};

std::set<Key> heldKeys;
std::vector<DrawCall> drawCalls;

class GameTest : public ::testing::Test {
  protected:
    void SetUp() override {
        heldKeys.clear();
        drawCalls.clear();
        initializeGame();
    }
};

} // namespace

// These fakes let the game tests control held keys and inspect draw requests
// without initializing SDL or a real renderer.
bool isKeyHeld(Key key) {
    return heldKeys.find(key) != heldKeys.end();
}

void drawFilledRect(Color color, Bounds bounds) {
    drawCalls.push_back(DrawCall{color, bounds});
}

TEST_F(GameTest, RendersBlueCatAndRedChefAtTheirStartingPositions) {
    renderGame();

    ASSERT_EQ(drawCalls.size(), 2u);

    EXPECT_EQ(drawCalls[0].color.blue, 255);
    EXPECT_EQ(drawCalls[0].color.red, 0);
    EXPECT_FLOAT_EQ(drawCalls[0].bounds.x, 100.0f);
    EXPECT_FLOAT_EQ(drawCalls[0].bounds.y, 250.0f);

    EXPECT_EQ(drawCalls[1].color.red, 255);
    EXPECT_EQ(drawCalls[1].color.blue, 0);
    EXPECT_FLOAT_EQ(drawCalls[1].bounds.x, 600.0f);
    EXPECT_FLOAT_EQ(drawCalls[1].bounds.y, 250.0f);
}

TEST_F(GameTest, WasdMovesOnlyTheCat) {
    heldKeys.insert(Key::D);

    updateGame(0.5f); // 200 units/second * 0.5 seconds = 100 units
    renderGame();

    ASSERT_EQ(drawCalls.size(), 2u);
    EXPECT_FLOAT_EQ(drawCalls[0].bounds.x, 200.0f);
    EXPECT_FLOAT_EQ(drawCalls[1].bounds.x, 600.0f);
}

TEST_F(GameTest, ArrowKeysMoveOnlyTheChef) {
    heldKeys.insert(Key::Left);

    updateGame(0.5f);
    renderGame();

    ASSERT_EQ(drawCalls.size(), 2u);
    EXPECT_FLOAT_EQ(drawCalls[0].bounds.x, 100.0f);
    EXPECT_FLOAT_EQ(drawCalls[1].bounds.x, 500.0f);
}

TEST_F(GameTest, UpdatesBothObjectsInTheSameFrame) {
    heldKeys.insert(Key::D);
    heldKeys.insert(Key::Left);

    updateGame(0.5f);
    renderGame();

    ASSERT_EQ(drawCalls.size(), 2u);
    EXPECT_FLOAT_EQ(drawCalls[0].bounds.x, 200.0f);
    EXPECT_FLOAT_EQ(drawCalls[1].bounds.x, 500.0f);
}
