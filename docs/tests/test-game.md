# test_game.cpp — Test Reference

> **Coverage:** Verified · **Source revision:** `feature/phase3-animation` @ `6749cec`
>
> **Test source:** [`tests/core/test_game.cpp`](../../tests/core/test_game.cpp)

**In one sentence:** It tests the Phase 1 [cat/chef game logic](../code/game.md) with **fake** input and drawing, so no SDL is needed.

**Why these tests matter:** They show the "fake the dependency" technique, and they check movement maths and which keys move which square.

## Setup and shared helpers

| Item | What it does |
| --- | --- |
| `DrawCall` | Records one `drawFilledRect` call (colour + bounds) |
| `heldKeys` | A `std::set<Key>` acting as the keyboard |
| `drawCalls` | Records every draw request |
| **Fake** `isKeyHeld(Key)` | Returns whether the key is in `heldKeys` (replaces [the real one](../code/input.md#iskeyheld)) |
| **Fake** `drawFilledRect(Color, Bounds)` | Appends to `drawCalls` (replaces [the real one](../code/platform.md#drawfilledrect)) |
| `GameTest::SetUp()` | Clears keys and draw calls, then calls [`initializeGame()`](../code/game.md#initializegame) |

**How the fakes work:** the `game_tests` executable links **only** `test_game.cpp` and `game.cpp`. `game.cpp` needs `isKeyHeld` and `drawFilledRect`, and the linker finds the fake versions defined in this test file.

## Individual tests

<a id="gametest-rendersbluecatandredchefattheirstartingpositions"></a>
### `GameTest.RendersBlueCatAndRedChefAtTheirStartingPositions`

[`renderGame()`](../code/game.md#rendergame) makes 2 draws: a blue cat at (100, 250) and a red chef at (600, 250).

<a id="gametest-wasdmovesonlythecat"></a>
### `GameTest.WasdMovesOnlyTheCat`

Holds D and updates 0.5 s. The cat moves to x = 200 (200 px/s × 0.5 s = 100 px) and the chef stays at 600.

<a id="gametest-arrowkeysmoveonlythechef"></a>
### `GameTest.ArrowKeysMoveOnlyTheChef`

Holds Left for 0.5 s. The chef moves to x = 500 and the cat stays at 100.

<a id="gametest-updatesbothobjectsinthesameframe"></a>
### `GameTest.UpdatesBothObjectsInTheSameFrame`

Holds D and Left. Both move in one update.

## Running these tests

**Target:** `game_tests`. **Command:** `./build/bin/game_tests`.

> ⚠️ **Not registered with CTest.** `tests/CMakeLists.txt` calls `gtest_discover_tests` only for `engine_tests`, so **`ctest` never runs these 4 tests**. That's why `ctest` reports 80 tests, not 84. CI doesn't run them either. Fix: add `gtest_discover_tests(game_tests)`.

**Back to:** [Test index](index.md) · [Code index](../code/index.md)
