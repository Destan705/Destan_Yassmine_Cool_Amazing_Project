# Test Index

**Every test should explain what could break and how the test would catch it.**

> **Coverage inventory** for `feature/phase3-animation` @ `6749cec`. 84 tests in 10 files: 80 run by `ctest` (`engine_tests`) and 4 in `game_tests`, which `ctest` **doesn't** run (see below).

| Test file | Code under test | Documented behavior | Documentation | Coverage |
| --- | --- | --- | --- | --- |
| `tests/rendering/test_renderer.cpp` | Renderer | Create/destroy, pixel-exact clears, rectangles, textures, bad handles | [test-renderer](test-renderer.md) | Verified |
| `tests/platform/test_platform.cpp` | platform | Init/shutdown safety, each start-up failure path | [test-platform](test-platform.md) | Verified |
| `tests/platform/test_input.cpp` | input | Key press translated to engine `Key` | [test-input](test-input.md) | Verified |
| `tests/platform/test_logger.cpp` | logger | Exact text and stream per level | [test-logger](test-logger.md) | Verified |
| `tests/core/test_engine.cpp` | engine | Quit/close stop the loop; failures return; restartable | [test-engine](test-engine.md) | Verified |
| `tests/core/test_game.cpp` | game (Phase 1) | Movement and drawing with fakes | [test-game](test-game.md) | Verified |
| `tests/ecs/test_component_entity.cpp` | Entity, Component | Add/find/duplicate/update | [test-component-entity](test-component-entity.md) | Verified |
| `tests/ecs/test_transform_sprite.cpp` | Transform, Sprite | Values, attachment, missing-Transform safety | [test-transform-sprite](test-transform-sprite.md) | Verified |
| `tests/events/test_event_dispatcher.cpp` | EventDispatcher | IDs, order, unsubscribe | [test-event-dispatcher](test-event-dispatcher.md) | Verified |
| `tests/scene/test_scene.cpp` | Scene, SceneManager | IDs, order, ownership, event timing | [test-scene](test-scene.md) | Verified |

## How to run

```sh
cmake --build build
ctest --test-dir build --output-on-failure   # engine_tests (80)
./build/bin/game_tests                        # game_tests (4), not in ctest
```

Run one group with `-R`, for example `ctest --test-dir build -R SceneManagerTest`.

## Known gaps (from reading the code)

| Area | Missing test |
| --- | --- |
| [AnimationComponent](../code/animation-component.md) | **No tests at all**: timing, looping vs hold, pause/resume/restart, constructor errors (assigned to Yassmine) |
| [Renderer::DrawTexture](../code/renderer.md#renderer-drawtexture) | The source-rectangle path (valid, out of bounds, zero/negative size) |
| [Sprite::sourceSet](../code/sprite.md#sprite-sourceset) | Cropped drawing through a sprite |
| `game_tests` | Not registered with CTest, so it never runs in CI |

## Reading a test page

A test page answers: *What is prepared? What action runs? What result is expected? Why does it matter?* For each fixture, also explain setup and cleanup. Include how tests are built or run only when the commands have been verified from CMake or scripts.

**Related:** [Code index](../code/index.md) · [Other project files](../project-files.md)
