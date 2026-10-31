# Scene — Source Reference

> **Coverage:** Verified · **Source revision:** `feature/phase3-animation` @ `6749cec` · **Last checked:** 2026-10-31
>
> **Files:** [`include/scene/scene.h`](../../include/scene/scene.h) and [`src/scene/scene.cpp`](../../src/scene/scene.cpp).

**In one sentence:** A named collection of entities that it owns, numbers, updates and draws in creation order.

**Why it exists:** It groups everything in one "level" or screen, so switching scenes swaps a whole set of entities at once (see [`SceneManager`](scene-manager.md)).

## Contents

| Symbol | What it means | Jump |
| --- | --- | --- |
| `Scene` | Container of entities | [Class](#class-scene) |
| `Scene(std::string)` | Create with a name | [Function](#scene-scene) |
| `getSceneName()` | Read the name | [Function](#scene-getscenename) |
| `createEntity()` | Make a new entity | [Function](#scene-createentity) |
| `update(float)` | Update all entities | [Function](#scene-update) |
| `render(Renderer&)` | Draw all entities | [Function](#scene-render) |

## Class: `Scene`

<a id="class-scene"></a>

**How it's created and destroyed:** `std::make_unique<Scene>("name")`, then handed to [`SceneManager::setActiveScene`](scene-manager.md#scenemanager-setactivescene), which owns it. When it's destroyed, all its entities (and their components) are destroyed too.

**Important rules:** entity IDs start at 1 and increase by 1. They're unique **per scene**, so two scenes can both have an entity 1.

### Fields

| Field | Type / initial value | Meaning | Who changes it |
| --- | --- | --- | --- |
| <a id="scene-scenename"></a>`sceneName` | `std::string` | Scene's name | Constructor |
| <a id="scene-entities"></a>`entities` | `std::vector<std::unique_ptr<Entity>>` | Owned entities in creation order | `createEntity`. **Owning.** |
| <a id="scene-idcounter"></a>`iDcounter` | `std::uint64_t`, `1` | Next entity ID | `createEntity` |

## Functions

<a id="scene-scene"></a>
### `explicit Scene::Scene(std::string name)`

Copies `name` into `sceneName` (assigned in the body, not in an initializer list). **No direct project-function calls.**

<a id="scene-getscenename"></a>
### `std::string Scene::getSceneName()`

Returns a **copy** of the name. It isn't marked `const`, so it can't be called on a `const Scene`. **Used by:** [`SceneManager::setActiveScene`](scene-manager.md#scenemanager-setactivescene).

<a id="scene-createentity"></a>
### `Entity& Scene::createEntity()`

**What it does:** Creates an [`Entity`](entity.md#entity-entity) with the next ID, stores it, increments the counter, and returns a reference.

**Returns:** `Entity&`, a **borrowed** reference valid while the scene lives. Because entities are stored behind `unique_ptr`, the reference stays valid even when the vector grows.

**Calls:** [`Entity::Entity`](entity.md#entity-entity) via `make_unique`. **Related tests:** [CreatesEntitiesWithUniqueIncreasingIds](../tests/test-scene.md#scenetest-createsentitieswithuniqueincreasingids).

<a id="scene-update"></a>
### `void Scene::update(float dt)`

Calls [`Entity::update`](entity.md#entity-update) on each entity in creation order. **Called by:** [`SceneManager::update`](scene-manager.md#scenemanager-update).

<a id="scene-render"></a>
### `void Scene::render(Renderer& renderer)`

Calls [`Entity::render`](entity.md#entity-render) on each entity in creation order. **Later entities draw on top.** **Called by:** [`renderPlatform`](platform.md#renderplatform). **Related tests:** [RendersEntitiesInInsertionOrder](../tests/test-scene.md#scenetest-rendersentitiesininsertionorder).

## Things worth knowing

- There's no way to remove an entity or look one up by ID yet.
- `scene.h` uses `Renderer&` without declaring it; it gets the forward declaration from `component.h` via `entity.h`.
- There's no read-only (`const`) way to walk the entities yet. The serializer ticket needs one ("agreed read-only traversal").

**Back to:** [Code index](index.md) · [Symbol index](symbol-index.md)
