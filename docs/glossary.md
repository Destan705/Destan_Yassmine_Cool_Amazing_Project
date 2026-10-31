# Glossary

Small explanations for terms used in this handbook.

| Term | Easy explanation |
| --- | --- |
| **AABB** | Axis-aligned bounding box: a rectangle that isn't rotated. [`Bounds`](code/render-types.md#struct-bounds) is one. (Collision is planned for Phase 3.) |
| **Back buffer** | The hidden image you draw into. `Present()` swaps it onto the screen. |
| **Component** | One piece of an [entity](code/entity.md), like its position ([Transform](code/transform.md)) or picture ([Sprite](code/sprite.md)). Subclass of [`Component`](code/component.md). |
| **Delta time (`dt`)** | **Seconds** since the previous frame. Multiplying speeds by it makes motion frame-rate independent. |
| **Destination rectangle** | **Where on screen** to draw, and how big. Comes from the Transform. |
| **Entity** | A game object: an ID plus a list of components. Owned by a [Scene](code/scene.md). |
| **Event dispatcher** | Code that calls every registered function when something happens. See [EventDispatcher](code/event-dispatcher.md). |
| **Fake** | A test-only replacement for a real function, so a test doesn't need SDL. See [test_game](tests/test-game.md). |
| **Fixture** | A GoogleTest class whose `SetUp`/`TearDown` run around every test (`TEST_F`). |
| **Frame (animation)** | One picture in an animation, i.e. one source rectangle on the sprite sheet. |
| **Handle** | A number that identifies a resource without exposing it. [`textureHandle`](code/render-types.md#rendertypes-texturehandle) 0 = none. |
| **Listener** | A function registered with the dispatcher. |
| **Owner / owning pointer** | The object responsible for deleting another (`std::unique_ptr`). A **borrowed** pointer or reference must never delete. |
| **RAII** | "Resource acquisition is initialization": the constructor grabs a resource and the destructor frees it, so clean-up happens automatically. |
| **Renderer** | The object that issues drawing commands. Here, [`Renderer`](code/renderer.md) wraps `SDL_Renderer`. |
| **Scancode** | SDL's number for a physical keyboard key. |
| **Scene** | A named set of entities, such as one level. |
| **Source rectangle** | **Which part of the texture image** to draw, in texture pixels. Used for sprite sheets. |
| **Sprite sheet** | One image holding several animation frames side by side. |
| **Vsync** | Waiting for the screen refresh before showing a frame, which caps the frame rate and stops tearing. |
