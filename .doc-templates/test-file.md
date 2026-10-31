# [test_file.cpp] — Test Reference

> **Coverage:** Draft / Verified · **Source revision:** [commit or branch]
>
> **Test source:** [`tests/path/to/test_file.cpp`](../../tests/path/to/test_file.cpp) (replace with verified path).

**In one sentence:** [Which behavior this file protects.]

**Why these tests matter:** [What kind of bug they are meant to catch.]

## Test coverage at a glance

| Test / fixture | What it checks | Jump | Code under test |
| --- | --- | --- | --- |
| `[Suite.Name]` | [Expected contract] | [Explanation](#suite-name) | [Function/class](../code/real-file.md#function-anchor) |

## Setup and shared helpers

### `[FixtureName]` (if present)

| Member / method | What it prepares or cleans up | Why |
| --- | --- | --- |
| `SetUp()` | [Create/reset mock state, test platform, etc.] | [Isolation reason] |
| `TearDown()` | [Restore globals, release resources, etc.] | [Avoid side effects] |
| `[fixture member]` | [Value and lifetime] | [How tests use it] |

Also explain any test-only factories, helpers, constants, mocks, fakes or global setup/cleanup.

## Individual tests

> Duplicate for every `TEST`, `TEST_F`, parameterized test and other test case present.

<a id="suite-name"></a>
### `[Suite.Name]`

**Tests:** [Specific behavior or contract.]

**Related production function(s):** [Deep links to documented code.]

| Stage | What happens |
| --- | --- |
| Given / setup | [Fixture data and initial state] |
| When / action | [Exact call(s) made] |
| Then / assertions | [Each important assertion and what it proves] |

**Why this test exists:** [Which regression it catches and why result matters.]

**Special cases:** [Failures, boundaries, empty input, ordering, nulls; if any.]

**Dependencies:** [SDL dummy drivers, fixtures, temporary files or platform assumptions if used.]

## Running these tests

**Build target:** [Verified CMake target.]

**Command:** `[Verified command]` or *Not confirmed yet.*

**What a failure usually points to:** [Module or invariant at risk.]

## Coverage gaps (if any)

[Missing success/failure paths you can demonstrate from source; do not guess.]

**Back to:** [Test index](index.md) · [Code index](../code/index.md)
