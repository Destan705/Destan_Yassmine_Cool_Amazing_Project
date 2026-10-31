# Game (Phase 1 demo logic) — Source Reference

> **Coverage:** Verified · **Source revision:** `feature/phase3-animation` @ `6749cec` · **Last checked:** 2026-10-31
>
> **Files:** [`include/core/game.h`](../../include/core/game.h) and [`src/core/game.cpp`](../../src/core/game.cpp).

**In one sentence:** The Phase 1 "cat and chef" demo: two coloured squares moved with WASD and the arrow keys.

**Why it exists:** It showed that input, update and rendering worked before the ECS/scene system existed. It is still compiled into the game and the tests, but **the current engine loop never calls it**.

## Contents

| Symbol | What it means | Jump |
| --- | --- | --- |
| Constants and positions | Start positions, size, speed, colours | [State](#state-and-types) |
| `updatePosition(...)` | Move one square based on keys | [Function](#updateposition) |
| `initializeGame()` | Reset positions | [Function](#initializegame) |
| `updateGame(float)` | Move both squares | [Function](#updategame) |
| `renderGame()` | Draw both squares | [Function](#rendergame) |

## State and types

<a id="state-and-types"></a>

All of these are inside an **anonymous namespace**, so they're private to `game.cpp`.

| Name | Kind / type | Value or initialization | What it means / where used |
| --- | --- | --- | --- |
| <a id="game-catstartposition"></a>`catStartPosition` | `constexpr std::array<float,2>` | `{100, 250}` | Cat's start (x, y) in pixels |
| <a id="game-chefstartposition"></a>`chefStartPosition` | `constexpr std::array<float,2>` | `{600, 250}` | Chef's start |
| <a id="game-catposition"></a>`catPosition` | `std::array<float,2>` | start value | Cat's current position |
| <a id="game-chefposition"></a>`chefPosition` | `std::array<float,2>` | start value | Chef's current position |
| <a id="game-objectsize"></a>`objectSize` | `constexpr float` | `100` | Square side length, in pixels |
| <a id="game-movementspeed"></a>`movementSpeed` | `constexpr float` | `200` | Pixels per second |
| <a id="game-catcolor"></a>`catColor` | `const Color` | `{0,0,255,255}` (blue) | Cat colour |
| <a id="game-chefcolor"></a>`chefColor` | `const Color` | `{255,0,0,255}` (red) | Chef colour |

## Functions

<a id="updateposition"></a>
### `void updatePosition(std::array<float,2>& position, float delta_time, Key left, Key right, Key up, Key down, const char* objectName)` (private)

**What it does:** Moves `position` by `movementSpeed × delta_time` in **one** direction, depending on which key is held. It also prints e.g. `Cat left`.

**Priority:** left, then right, then up, then down (an `else if` chain). Holding two keys moves in only one direction, and diagonal movement isn't possible.

**Calls:** [`isKeyHeld`](input.md#iskeyheld) to read each direction key.

<a id="initializegame"></a>
### `void initializeGame()`

Resets both positions to their start values. **No direct project-function calls.** **Used by:** `GameTest::SetUp`.

<a id="updategame"></a>
### `void updateGame(float delta_time)`

Calls [`updatePosition`](#updateposition) for the cat (W/A/S/D) and the chef (arrow keys). `delta_time` is in seconds.

<a id="rendergame"></a>
### `void renderGame()`

Draws the cat, then the chef, as `objectSize` squares via [`drawFilledRect`](platform.md#drawfilledrect).

## Things worth knowing

- `game.h` has **no `#pragma once`** and includes `<array>` without needing it.
- **Unused at runtime:** `engine()` doesn't call any of these. Consider removing it, or turning it into a component, in a later phase.
- **Tests:** [GameTest](../tests/test-game.md) replaces `isKeyHeld` and `drawFilledRect` with fakes, so these functions are tested without SDL.

**Back to:** [Code index](index.md) · [Symbol index](symbol-index.md)
