# Code Files & Modules

**Find a source file, see its responsibility, and open its documentation.**

> **Coverage inventory** for `feature/phase3-animation` @ `6749cec` (checked 2026-10-31). Every tracked file under `include/` and `src/` is listed.

| Module / file pair | What it owns or does | Documentation | Coverage |
| --- | --- | --- | --- |
| `src/main.cpp` | Program entry; calls `engine()` | [Engine loop](engine.md#main) | Verified |
| `include/core/engine.h` · `src/core/engine.cpp` | Start-up, demo scene, frame loop, shutdown | [Engine loop](engine.md) | Verified |
| `include/core/game.h` · `src/core/game.cpp` | Phase 1 cat/chef demo (not called by the engine) | [Game](game.md) | Verified |
| `include/platform/platform.h` · `src/platform/platform.cpp` | SDL start/stop, window, global Renderer, scene drawing, texture loading | [Platform](platform.md) | Verified |
| `include/rendering/render_api.h` (implemented in `platform.cpp`) | Phase 1 free drawing functions | [Render API](render-api.md) | Verified |
| `include/platform/input.h` · `src/platform/input.cpp` | Event pump, quit detection, keyboard state | [Input](input.md) | Verified |
| `include/platform/logger.h` · `src/platform/logger.cpp` | Labelled console logging | [Logger](logger.md) | Verified |
| `include/rendering/renderer.h` · `src/rendering/renderer.cpp` | SDL renderer wrapper; owns textures | [Renderer](renderer.md) | Verified |
| `include/rendering/rendertypes.h` | `textureHandle`, `Color`, `Bounds` | [Render types](render-types.md) | Verified |
| `include/ecs/component.h` · `src/ecs/component.cpp` | Component base class | [Component](component.md) | Verified |
| `include/ecs/entity.h` · `src/ecs/entity.cpp` | Entity: owns components | [Entity](entity.md) | Verified |
| `include/ecs/transform.h` | Position and size component | [Transform](transform.md) | Verified |
| `include/ecs/sprite.h` · `src/ecs/sprite.cpp` | Draws a texture at the Transform | [Sprite](sprite.md) | Verified |
| `include/ecs/animationComponent.h` · `src/ecs/animationComponent.cpp` | Sprite-sheet animation | [AnimationComponent](animation-component.md) | Verified |
| `include/events/event_dispatcher.h` · `src/events/event_dispatcher.cpp` | Subscribe/dispatch for `SceneChangedEvent` | [EventDispatcher](event-dispatcher.md) | Verified |
| `include/scene/scene.h` · `src/scene/scene.cpp` | Named set of entities | [Scene](scene.md) | Verified |
| `include/scene/scene_manager.h` · `src/scene/scene_manager.cpp` | Owns and swaps the active scene | [SceneManager](scene-manager.md) | Verified |

### Coverage statuses

- **Not started:** source file found, documentation missing.
- **Draft:** written, but links/behavior are not yet checked against source.
- **Verified:** all documented symbols and behavior checked against the selected revision.

### Not covered here

- Tests: see the [test index](../tests/index.md).
- CMake, CI, formatting and assets: see [other project files](../project-files.md).
- `build/`: generated, so it isn't documented file by file.

**Find a particular method:** [Symbol index](symbol-index.md). **How to write a new page:** [Documentation guide](../contributing.md).
