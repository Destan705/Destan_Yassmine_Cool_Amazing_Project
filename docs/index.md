# The Game Engine Handbook

**A guided tour of the code: what it does, how its parts connect, and where to find everything.**

> **Status:** Verified against `feature/phase3-animation` @ `6749cec` (2026-10-31). Covers Phase 2 plus Phase 3 source rectangles and animation. Collider, sound, AssetManager and the scene serializer **are not implemented yet** and aren't described as if they were.

## Choose where to start

| I want to… | Go to |
| --- | --- |
| Understand the big picture | [Architecture overview](architecture/index.md) |
| Follow one engine frame | [Frame flow](architecture/frame-flow.md) |
| Know who owns and deletes what | [Ownership and lifetime](architecture/ownership.md) |
| Find a class, function, field, or constant | [Symbol index](code/symbol-index.md) |
| Look up a `.h`/`.cpp` pair | [Code file index](code/index.md) |
| Understand a test | [Test index](tests/index.md) |
| Find CMake, CI, assets, or `build/` | [Other project files](project-files.md) |
| Learn project terms | [Glossary](glossary.md) |
| Add or change documentation | [Documentation guide](contributing.md) |

## Quick how-tos (using real API names)

**Add a textured object:**

```cpp
Entity& e = sceneManager.getActiveScene().createEntity();
Transform& t = e.addComponent<Transform>();
t.x = 100; t.y = 150; t.width = 50; t.height = 50;
e.addComponent<Sprite>(loadPlatformTexture("assets/test.bmp"));
```

**Make it animated** (sprite sheet with 4 frames of 32×32, 0.25 s each, looping):

```cpp
std::vector<Bounds> frames = {{0,0,32,32}, {32,0,32,32}, {64,0,32,32}, {96,0,32,32}};
e.addComponent<AnimationComponent>(frames, 0.25f, true);
```

See [AnimationComponent](code/animation-component.md) and [Sprite](code/sprite.md).

## How to read a code page

Each code page tells you:

1. **Purpose**: what that file or class is responsible for.
2. **Contents**: classes, fields, constants and functions, with clickable links.
3. **Behavior**: what each function receives, does, changes and returns.
4. **Connections**: what calls it, what it calls, *why*, and where to read those other functions.
5. **Things to watch**: ownership, errors, assumptions, edge cases, tests.

## Issues found while documenting

These are **observations**, not changes. The code wasn't modified.

| # | Issue | Where |
| --- | --- | --- |
| 1 | `game_tests` isn't registered with CTest, so its 4 tests never run in `ctest` or CI | [test_game](tests/test-game.md) |
| 2 | `loadPlatformTexture` uses paths relative to the working directory, but `initializePlatform` uses the executable folder, so the demo only works when launched from the repo root | [platform](code/platform.md#loadplatformtexture) |
| 3 | A missing asset during scene set-up throws out of `engine()` without `shutdownPlatform()` | [engine](code/engine.md#engine) |
| 4 | No tests for `AnimationComponent` or for `DrawTexture` with a source rectangle | [test index](tests/index.md) |
| 5 | "Invalid source rectangle" warning logs every frame (no warn-once) | [Renderer](code/renderer.md#renderer-drawtexture) |
| 6 | `engine.h`, `game.h`, `input.h`, `render_api.h` lack `#pragma once`; `entity.h` uses `std::logic_error` without `<stdexcept>` | code pages |
| 7 | `typeid(*component)` compiler warning on every build | [Entity](code/entity.md#entity-getcomponent) |
| 8 | CI doesn't check `clang-format`; `renderer.*` and `sprite.*` aren't formatted | [project files](project-files.md) |
| 9 | `.DS_Store` is committed | [project files](project-files.md) |

## The main idea

> Explain the code as though someone else will maintain it next month. Describe what the implementation actually does, not what its author hoped it would do.
