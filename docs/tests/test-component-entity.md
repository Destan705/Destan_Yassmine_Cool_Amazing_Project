# test_component_entity.cpp — Test Reference

> **Coverage:** Verified · **Source revision:** `feature/phase3-animation` @ `6749cec`
>
> **Test source:** [`tests/ecs/test_component_entity.cpp`](../../tests/ecs/test_component_entity.cpp)

**In one sentence:** It checks the basic [`Entity`](../code/entity.md) contract: add, find, reject duplicates, and forward `update`.

## Setup and shared helpers

| Helper | What it is |
| --- | --- |
| `FakeComponent`, `FakeComponent2` | Empty `Component` subclasses (`FakeComponent2` isn't used) |
| `UpdateTracker` | A component whose `update` sets `updated = true` |

## Individual tests

<a id="entitytest-addcomponentreturnsthecomponent"></a>
### `EntityTest.AddComponentReturnsTheComponent`

The reference from [`addComponent`](../code/entity.md#entity-addcomponent) is the same object [`getComponent`](../code/entity.md#entity-getcomponent) finds.

<a id="entitytest-addingduplicatecomponentthrows"></a>
### `EntityTest.AddingDuplicateComponentThrows`

A second `addComponent<FakeComponent>()` throws `std::logic_error`.

<a id="entitytest-getmissingcomponentreturnsnullptr"></a>
### `EntityTest.GetMissingComponentReturnsNullptr`

`getComponent` on an empty entity returns `nullptr`.

<a id="entitytest-updatereachescomponents"></a>
### `EntityTest.UpdateReachesComponents`

[`entity.update(0.1f)`](../code/entity.md#entity-update) reaches the component's override.

## Coverage gaps

No test for `render` forwarding at entity level (covered at scene level), the owner being set (covered in [Transform/Sprite tests](test-transform-sprite.md)), or the exact-type rule for subclasses.

**Back to:** [Test index](index.md) · [Code index](../code/index.md)
