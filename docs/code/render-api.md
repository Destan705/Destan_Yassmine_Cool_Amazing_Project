# Render API (Phase 1) — Source Reference

> **Coverage:** Verified · **Source revision:** `feature/phase3-animation` @ `6749cec` · **Last checked:** 2026-10-31
>
> **Files:** [`include/rendering/render_api.h`](../../include/rendering/render_api.h). **Implemented in** [`src/platform/platform.cpp`](../../src/platform/platform.cpp).

**In one sentence:** Four free functions that let code draw without knowing about `Renderer` or SDL: begin a frame, draw a rectangle, draw the start-up texture, and present.

**Why it exists:** It is the Phase 1 drawing interface for [`game.cpp`](game.md). It also lets `game_tests` swap in **fake** versions, so game logic can be tested without SDL.

## Contents

| Symbol | What it means | Jump |
| --- | --- | --- |
| `beginFrame()` | Clear to black | [Docs](platform.md#beginframe) |
| `drawFilledRect(Color, Bounds)` | Draw a rectangle | [Docs](platform.md#drawfilledrect) |
| `drawTexture()` | Draw the start-up texture | [Docs](platform.md#drawtexture) |
| `presentFrame()` | Show the frame | [Docs](platform.md#presentframe) |

The full function explanations live on the [Platform page](platform.md), because that's where the code is.

## Things worth knowing

- **No include guard:** `render_api.h` has no `#pragma once`. Including it twice in one file would be harmless here (it only has declarations), but it's inconsistent with the other headers.
- **Current status:** the Phase 2/3 engine loop draws through [`renderPlatform`](platform.md#renderplatform) instead. This API is used only by [`renderGame`](game.md#rendergame) and tests.

**Back to:** [Code index](index.md) · [Symbol index](symbol-index.md)
