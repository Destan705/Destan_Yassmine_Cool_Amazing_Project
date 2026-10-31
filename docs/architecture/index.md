# Architecture Overview

> **Coverage:** Verified · **Checked against:** `feature/phase3-animation` @ `6749cec`

**In one sentence:** A small layered engine. A frame loop drives a scene of entities made of components, and a platform layer hides SDL behind a `Renderer`.

## Big picture

```mermaid
flowchart TD
    main["main()"] --> engine["engine() — frame loop"]
    engine -->|start/stop, draw, load textures| platform["platform.cpp"]
    engine -->|events, quit| input["input.cpp"]
    engine -->|owns| ED["EventDispatcher"]
    engine -->|owns| SM["SceneManager"]
    SM -->|owns 1| Scene
    SM -.->|borrows, dispatches| ED
    Scene -->|owns many| Entity
    Entity -->|owns many| Comp["Component (Transform, Sprite, AnimationComponent)"]
    platform -->|owns 1| Renderer
    Renderer -->|owns| Tex["SDL textures"]
    Comp -.->|"Sprite: DrawTexture(handle)"| Renderer
    Renderer --> SDL[(SDL3)]
    platform --> SDL
    input --> SDL
```

**How to read this:** solid arrows are **ownership or direct calls**; dotted arrows are **borrowed references** (no ownership).

## Layers

| Layer | Files | Knows about SDL? |
| --- | --- | --- |
| Entry / loop | [main, engine](../code/engine.md) | Only through platform/input functions |
| Scene & ECS | [SceneManager](../code/scene-manager.md), [Scene](../code/scene.md), [Entity](../code/entity.md), [Component](../code/component.md), [Transform](../code/transform.md), [Sprite](../code/sprite.md), [AnimationComponent](../code/animation-component.md) | **No.** They use [render types](../code/render-types.md) and a `Renderer&` |
| Events | [EventDispatcher](../code/event-dispatcher.md) | No |
| Platform | [platform](../code/platform.md), [input](../code/input.md), [logger](../code/logger.md) | Yes (except the logger) |
| Rendering | [Renderer](../code/renderer.md) | Yes. `renderer.h` is the header that includes SDL. |

**SDL-free headers:** `rendertypes.h`, `component.h`, `entity.h`, `transform.h`, `sprite.h`, `animationComponent.h`, `scene.h`, `scene_manager.h`, `event_dispatcher.h`, `platform.h` (it forward-declares `Renderer`), `logger.h`, `input.h`.

## Who owns what

| Object | Owner | How | Destroyed when |
| --- | --- | --- | --- |
| SDL window | platform global `window` | raw pointer | [`shutdownPlatform`](../code/platform.md#shutdownplatform) or an init failure |
| `Renderer` | platform global `renderer` | `unique_ptr` | `shutdownPlatform`, **before** the window |
| SDL textures | `Renderer::textures` | raw pointers in a vector | `~Renderer` |
| `EventDispatcher` | local in `engine()` | stack | end of the inner scope, **after** the SceneManager |
| `SceneManager` | local in `engine()` | stack | end of the inner scope |
| Active `Scene` | `SceneManager::currentScene` | `unique_ptr` | replaced, or the manager is destroyed |
| `Entity` | `Scene::entities` | `unique_ptr` each | the scene is destroyed |
| Components | `Entity::components` | `unique_ptr<Component>` each | the entity is destroyed |

**Borrowed (non-owning) links:** `Component::owner` → Entity; `SceneManager::eventDispatcher` → dispatcher; `Sprite::currentTexture` is a **number**, not a pointer, so it can't dangle in memory terms.

See [ownership and lifetime](ownership.md) for the full start-up and shutdown order.

## Answers to the key questions

- **Where does execution start?** `main()` → [`engine()`](../code/engine.md#engine).
- **What stops the loop?** [`processPlatformEvents`](../code/input.md#processplatformevents) returns false on `SDL_EVENT_QUIT` or `SDL_EVENT_WINDOW_CLOSE_REQUESTED`.
- **How do update and render travel?** `SceneManager::update` → `Scene::update` → `Entity::update` → each `Component::update`. Rendering goes `renderPlatform` → `Scene::render` → `Entity::render` → each `Component::render`. See the [frame flow](frame-flow.md).
- **Events:** only `SceneChangedEvent`, dispatched synchronously by [`setActiveScene`](../code/scene-manager.md#scenemanager-setactivescene). Nothing in the game subscribes yet.
- **Failure paths:** start-up failure cleans itself up and `engine()` returns. A missing texture during scene set-up throws out of `engine()` uncaught.

**Next:** [A frame in the engine](frame-flow.md) · [Ownership and lifetime](ownership.md) · [File reference](../code/index.md)
