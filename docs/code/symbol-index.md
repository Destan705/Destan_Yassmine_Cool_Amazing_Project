# Symbol Index

**An alphabetical jump list for every class, method, function, field, enum and constant.**

> Checked against `feature/phase3-animation` @ `6749cec`. Alphabetised by the name after any `Class::` prefix is ignored.

| Symbol (exact name) | Kind | One-line purpose | Jump to explanation |
| --- | --- | --- | --- |
| `Entity::addComponent<T>(Args&&...)` | template method | Create and attach a component | [Jump](entity.md#entity-addcomponent) |
| `AnimationComponent` | class | Sprite-sheet animator | [AnimationComponent](animation-component.md#class-animationcomponent) |
| `AnimationComponent::AnimationComponent(const std::vector<Bounds>&, float, bool)` | constructor | Validate and store frames | [Jump](animation-component.md#animationcomponent-animationcomponent) |
| `Color::alpha` | field | Opacity 0–255 | [Jump](render-types.md#color-alpha) |
| `beginFrame()` | free function | Old API: clear to black | [Jump](platform.md#beginframe) |
| `Color::blue` | field | Blue 0–255 | [Jump](render-types.md#color-blue) |
| `Bounds` | struct | Rectangle in pixels | [Jump](render-types.md#struct-bounds) |
| `catColor` | constant | Cat is blue | [Jump](game.md#game-catcolor) |
| `catPosition` | variable | Cat's position | [Jump](game.md#game-catposition) |
| `catStartPosition` | constant | Cat's start | [Jump](game.md#game-catstartposition) |
| `chefColor` | constant | Chef is red | [Jump](game.md#game-chefcolor) |
| `chefPosition` | variable | Chef's position | [Jump](game.md#game-chefposition) |
| `chefStartPosition` | constant | Chef's start | [Jump](game.md#game-chefstartposition) |
| `Renderer::ClearScreen(const Color&)` | method | Fill the frame with a colour | [Jump](renderer.md#renderer-clearscreen) |
| `Color` | struct | RGBA colour | [Jump](render-types.md#struct-color) |
| `Component` | class | Base for all components | [Jump](component.md#class-component) |
| `Entity::components` | field | Owned components | [Jump](entity.md#entity-components) |
| `Scene::createEntity()` | method | Make a new entity | [Jump](scene.md#scene-createentity) |
| `AnimationComponent::currentFrame` | field | Frame being shown | [Jump](animation-component.md#animationcomponent-currentframe) |
| `SceneManager::currentScene` | field | Owned active scene | [Jump](scene-manager.md#scenemanager-currentscene) |
| `currentTexture` (platform global) | global | Start-up texture handle | [Jump](platform.md#platform-currenttexture) |
| `Sprite::currentTexture` | field | Sprite's texture handle | [Jump](sprite.md#sprite-currenttexture) |
| `EventDispatcher::dispatch(const SceneChangedEvent&)` | method | Call all listeners | [Jump](event-dispatcher.md#eventdispatcher-dispatch) |
| `drawFilledRect(Color, Bounds)` | free function | Old API: rectangle | [Jump](platform.md#drawfilledrect) |
| `Renderer::DrawFilledRect(const Color&, const Bounds&)` | method | Draw a solid rectangle | [Jump](renderer.md#renderer-drawfilledrect) |
| `drawTexture()` | free function | Old API: draw start-up texture | [Jump](platform.md#drawtexture) |
| `Renderer::DrawTexture(textureHandle, const Bounds&, std::optional<Bounds>)` | method | Draw texture, optionally cropped | [Jump](renderer.md#renderer-drawtexture) |
| `AnimationComponent::duration` | field | Seconds per frame | [Jump](animation-component.md#animationcomponent-duration) |
| `AnimationComponent::elapsed` | field | Time on current frame | [Jump](animation-component.md#animationcomponent-elapsed) |
| `engine()` | free function | Whole engine lifetime | [Jump](engine.md#engine) |
| `Entity` | class | Game object owning components | [Jump](entity.md#class-entity) |
| `Entity::Entity(std::uint64_t)` | constructor | Create with ID | [Jump](entity.md#entity-entity) |
| `entities` (Scene) | field | Owned entities | [Jump](scene.md#scene-entities) |
| `event` (input global) | global | SDL event scratch | [Jump](input.md#input-event) |
| `EventDispatcher` | class | Subscribe/notify hub | [Jump](event-dispatcher.md#class-eventdispatcher) |
| `SceneManager::eventDispatcher` | field | Borrowed dispatcher | [Jump](scene-manager.md#scenemanager-eventdispatcher) |
| `AnimationComponent::frames` | field | Source rectangles | [Jump](animation-component.md#animationcomponent-frames) |
| `SceneManager::getActiveScene()` | method | Access active scene | [Jump](scene-manager.md#scenemanager-getactivescene) |
| `Entity::getComponent<T>()` | template method | Find component by exact type | [Jump](entity.md#entity-getcomponent) |
| `Entity::getId()` | method | Read ID | [Jump](entity.md#entity-getid) |
| `Component::getOwner()` | method | Owning entity | [Jump](component.md#component-getowner) |
| `Scene::getSceneName()` | method | Read name | [Jump](scene.md#scene-getscenename) |
| `Color::green` | field | Green 0–255 | [Jump](render-types.md#color-green) |
| `Bounds::h` | field | Height | [Jump](render-types.md#bounds-h) |
| `EventDispatcher::Handler` | type alias | Listener function type | [Jump](event-dispatcher.md#eventdispatcher-handler) |
| `Renderer::hasWarned` | field | Warn-once flag | [Jump](renderer.md#renderer-haswarned) |
| `Transform::height` | field | Height | [Jump](transform.md#transform-height) |
| `Entity::id` | field | Entity ID | [Jump](entity.md#entity-id) |
| `EventDispatcher::idCounter` | field | Next listener ID | [Jump](event-dispatcher.md#eventdispatcher-idcounter) |
| `Scene::iDcounter` | field | Next entity ID | [Jump](scene.md#scene-idcounter) |
| `initializeGame()` | free function | Reset demo positions | [Jump](game.md#initializegame) |
| `initializeInput()` | free function | Get SDL keyboard array | [Jump](input.md#initializeinput) |
| `initializePlatform()` | free function | Start SDL, window, renderer | [Jump](platform.md#initializeplatform) |
| `isKeyHeld(Key)` | free function | Key currently down? | [Jump](input.md#iskeyheld) |
| `Key` | enum class | Engine key names | [Jump](input.md#input-key) |
| `keystate` | global | SDL keyboard array | [Jump](input.md#input-keystate) |
| `EventDispatcher::ListenerId` | type alias | Subscription ID | [Jump](event-dispatcher.md#eventdispatcher-listenerid) |
| `loadPlatformTexture(const char*)` | free function | Load BMP via platform | [Jump](platform.md#loadplatformtexture) |
| `Renderer::LoadTexture(const char*)` | method | Load BMP into texture | [Jump](renderer.md#renderer-loadtexture) |
| `logger_level` | enum class | Info / Warning / Error | [Jump](logger.md#logger-level) |
| `loggerLevelToString(logger_level)` | free function | Level → label | [Jump](logger.md#loggerleveltostring) |
| `logMessage(logger_level, const std::string&)` | free function | Print labelled message | [Jump](logger.md#logmessage) |
| `main()` | free function | Program entry | [Jump](engine.md#main) |
| `movementSpeed` | constant | 200 px/s | [Jump](game.md#game-movementspeed) |
| `SceneChangedEvent::newSceneName` | field | New scene name | [Jump](event-dispatcher.md#scenechangedevent-newscenename) |
| `objectSize` | constant | 100 px squares | [Jump](game.md#game-objectsize) |
| `SceneChangedEvent::oldSceneName` | field | Old scene name | [Jump](event-dispatcher.md#scenechangedevent-oldscenename) |
| `Component::owner` | field | Back-pointer to entity | [Jump](component.md#component-owner) |
| `AnimationComponent::pause()` | method | Freeze animation | [Jump](animation-component.md#animationcomponent-pause) |
| `AnimationComponent::paused` | field | Paused flag | [Jump](animation-component.md#animationcomponent-paused) |
| `Renderer::Present()` | method | Show frame | [Jump](renderer.md#renderer-present) |
| `presentFrame()` | free function | Old API: present | [Jump](platform.md#presentframe) |
| `pressedThisFrame` | global | Keys pressed this frame | [Jump](input.md#input-pressedthisframe) |
| `processPlatformEvents()` | free function | Pump events; false on quit | [Jump](input.md#processplatformevents) |
| `Color::red` | field | Red 0–255 | [Jump](render-types.md#color-red) |
| `releasedThisFrame` | global | Keys released this frame | [Jump](input.md#input-releasedthisframe) |
| `Component::render(Renderer&)` | virtual method | Drawing hook | [Jump](component.md#component-render) |
| `Entity::render(Renderer&)` | method | Render all components | [Jump](entity.md#entity-render) |
| `Scene::render(Renderer&)` | method | Render all entities | [Jump](scene.md#scene-render) |
| `Sprite::render(Renderer&)` | method | Draw texture | [Jump](sprite.md#sprite-render) |
| `renderEngineFrame(SceneManager&)` | free function | Draw active scene | [Jump](engine.md#renderengineframe) |
| `Renderer` | class | SDL renderer wrapper | [Jump](renderer.md#class-renderer) |
| `renderer` (platform global) | global | The engine's Renderer | [Jump](platform.md#platform-renderer) |
| `Renderer::renderer` | field | Owned `SDL_Renderer*` | [Jump](renderer.md#renderer-renderer-field) |
| `Renderer::Renderer(SDL_Window*)` | constructor | Create SDL renderer | [Jump](renderer.md#renderer-renderer) |
| `Renderer::~Renderer()` | destructor | Free textures and renderer | [Jump](renderer.md#renderer-destructor) |
| `renderGame()` | free function | Draw cat and chef | [Jump](game.md#rendergame) |
| `renderPlatform(Scene&)` | free function | Clear, draw scene, present | [Jump](platform.md#renderplatform) |
| `AnimationComponent::repeat` | field | Loop or hold last | [Jump](animation-component.md#animationcomponent-repeat) |
| `AnimationComponent::restart()` | method | Back to frame 0 | [Jump](animation-component.md#animationcomponent-restart) |
| `AnimationComponent::resume()` | method | Unfreeze | [Jump](animation-component.md#animationcomponent-resume) |
| `Scene` | class | Named set of entities | [Jump](scene.md#class-scene) |
| `Scene::Scene(std::string)` | constructor | Create with name | [Jump](scene.md#scene-scene) |
| `SceneChangedEvent` | struct | Old/new scene names | [Jump](event-dispatcher.md#struct-scenechangedevent) |
| `SceneManager` | class | Owns active scene | [Jump](scene-manager.md#class-scenemanager) |
| `SceneManager::SceneManager(EventDispatcher&)` | constructor | Bind dispatcher | [Jump](scene-manager.md#scenemanager-scenemanager) |
| `Scene::sceneName` | field | Name | [Jump](scene.md#scene-scenename) |
| `SceneManager::setActiveScene(std::unique_ptr<Scene>)` | method | Swap scene, dispatch event | [Jump](scene-manager.md#scenemanager-setactivescene) |
| `Component::setOwner(Entity&)` | private method | Set back-pointer | [Jump](component.md#component-setowner) |
| `shutdownPlatform()` | free function | Release everything | [Jump](platform.md#shutdownplatform) |
| `Sprite::sourceSet(std::optional<Bounds>)` | method | Set source crop | [Jump](sprite.md#sprite-sourceset) |
| `Sprite` | class | Draws a texture | [Jump](sprite.md#class-sprite) |
| `Sprite::Sprite(textureHandle)` | constructor | Store handle | [Jump](sprite.md#sprite-sprite) |
| `Sprite::src` | field | Source crop | [Jump](sprite.md#sprite-src) |
| `EventDispatcher::subscribe(Handler)` | method | Add listener | [Jump](event-dispatcher.md#eventdispatcher-subscribe) |
| `EventDispatcher::subscriptions` | field | Listener list | [Jump](event-dispatcher.md#eventdispatcher-subscriptions) |
| `textureHandle` | type alias | Texture ID (0 = none) | [Jump](render-types.md#rendertypes-texturehandle) |
| `Renderer::textures` | field | Owned textures (index = handle) | [Jump](renderer.md#renderer-textures) |
| `toSDLScancode(Key)` | free function | Key → SDL scancode | [Jump](input.md#tosdlscancode) |
| `Transform` | class | Position and size | [Jump](transform.md#class-transform) |
| `EventDispatcher::unsubscribe(ListenerId)` | method | Remove listener | [Jump](event-dispatcher.md#eventdispatcher-unsubscribe) |
| `AnimationComponent::update(float)` | method | Advance animation | [Jump](animation-component.md#animationcomponent-update) |
| `Component::update(float)` | virtual method | Logic hook | [Jump](component.md#component-update) |
| `Entity::update(float)` | method | Update all components | [Jump](entity.md#entity-update) |
| `Scene::update(float)` | method | Update all entities | [Jump](scene.md#scene-update) |
| `SceneManager::update(float)` | method | Update active scene | [Jump](scene-manager.md#scenemanager-update) |
| `updateGame(float)` | free function | Move cat and chef | [Jump](game.md#updategame) |
| `updatePosition(...)` | private function | Move one square | [Jump](game.md#updateposition) |
| `Bounds::w` | field | Width | [Jump](render-types.md#bounds-w) |
| `wasKeyPressed(Key)` | free function | Pressed this frame? | [Jump](input.md#waskeypressed) |
| `wasKeyReleased(Key)` | free function | Released this frame? | [Jump](input.md#waskeyreleased) |
| `Transform::width` | field | Width | [Jump](transform.md#transform-width) |
| `window` | global | SDL window | [Jump](platform.md#platform-window) |
| `Bounds::x` | field | Left edge | [Jump](render-types.md#bounds-x) |
| `Transform::x` | field | Left edge | [Jump](transform.md#transform-x) |
| `Bounds::y` | field | Top edge | [Jump](render-types.md#bounds-y) |
| `Transform::y` | field | Top edge | [Jump](transform.md#transform-y) |
| `Component::~Component()` | virtual destructor | Proper subclass clean-up | [Jump](component.md#component-destructor) |

## Naming rules

- Use qualified names, for example `Scene::render(...)`, and include enough parameter types to distinguish overloads.
- Alphabetize by the name shown in source, ignoring scope punctuation where practical.
- Use an explicit, unique anchor on the destination page, such as `<a id="scene-render"></a>`.
- For a field, link to its row under the class's **Fields** section; for meaningful variables not owned by a class, link to the module's **State and types** section.
- If a private helper matters only inside its `.cpp`, it **still** belongs here.
