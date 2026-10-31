# Other Project Files

> **Coverage:** Verified · **Checked against:** `feature/phase3-animation` @ `6749cec`

**In one sentence:** The build scripts, CI, code-style tools, assets and Git settings that support the engine code.

## Build and project setup

| File/folder | What it does | Details |
| --- | --- | --- |
| [`CMakeLists.txt`](../CMakeLists.txt) (root) | C++20, downloads dependencies, adds `src` and `tests` | [Below](#root-cmakeliststxt) |
| [`src/CMakeLists.txt`](../src/CMakeLists.txt) | Builds the `game_engine` executable | [Below](#srccmakeliststxt) |
| [`tests/CMakeLists.txt`](../tests/CMakeLists.txt) | Builds `engine_tests` and `game_tests` | [Below](#testscmakeliststxt) |
| [`.github/workflows/ci.yml`](../.github/workflows/ci.yml) | CI: build, clang-tidy, tests | [Below](#githubworkflowsciyml) |
| [`.clang-format`](../.clang-format) | Code style | [Below](#clang-format) |
| [`.clang-tidy`](../.clang-tidy) | Static-analysis checks | [Below](#clang-tidy) |
| [`.gitignore`](../.gitignore) | Ignored files | `build/`, `CMakeFiles/`, `site/` |
| `assets/` | Images used by the demo and tests | [Below](#assets) |
| `.DS_Store` | macOS Finder metadata, **committed by accident** | Can be removed and added to `.gitignore` |
| Docs tooling: `mkdocs.yml`, `check_doc_links.py`, `CLAUDE_DOCS_PROMPT.md`, `.doc-templates/` | This handbook | [Documentation guide](contributing.md) |

<a id="root-cmakeliststxt"></a>
### Root `CMakeLists.txt`

| Item | Value | Why it matters |
| --- | --- | --- |
| `cmake_minimum_required` | 3.20 | Needed for `FetchContent_MakeAvailable` |
| `ENGINE_INCLUDE_DIRS` | `include/` and its 6 subfolders | Lets code write `#include "scene.h"` without folder paths |
| `CMAKE_EXPORT_COMPILE_COMMANDS` | ON | Creates `build/compile_commands.json` for clang-tidy and editors |
| `FetchContent` SDL3 | `release-3.4.16` | Downloaded and built from source on first configure |
| `FetchContent` googletest | `v1.15.2` | Test framework |
| `CMAKE_RUNTIME_OUTPUT_DIRECTORY` | `build/bin` | All executables end up in `build/bin/` |
| C++ standard | 20, required | |
| `enable_testing()` | | Turns on CTest |

<a id="srccmakeliststxt"></a>
### `src/CMakeLists.txt`

Builds **`game_engine`** from every `.cpp` in `src/` (each must be listed **by hand**, so add new files here). It links `SDL3::SDL3`. Post-build steps copy `SDL3.dll` next to the executable (Windows only) and copy `assets/` next to the executable.

<a id="testscmakeliststxt"></a>
### `tests/CMakeLists.txt`

| Target | Contents | Registered with CTest? |
| --- | --- | --- |
| `engine_tests` | All test files except `test_game.cpp`, **plus** the engine `.cpp` files listed again (`../src/...`) | Yes, via `gtest_discover_tests` (`PRE_TEST`, working dir = project root, 30 s timeout) |
| `game_tests` | `test_game.cpp` + `game.cpp` only (with fakes) | **No**, so `ctest` and CI skip it |

**Gotcha:** a new engine `.cpp` must be added to **both** `src/CMakeLists.txt` and the `engine_tests` list, otherwise you get linker "undefined symbols" errors in the tests.

<a id="githubworkflowsciyml"></a>
### `.github/workflows/ci.yml`

| Question | Answer |
| --- | --- |
| Triggers | Push to `main`; pull requests into `main`, `feature/platform-integration`, `phase2` |
| Runner | `ubuntu-latest` |
| Steps | Checkout → install SDL's Linux build dependencies + Xvfb → `cmake -B build` → `cmake --build build` → `clang-tidy` on `src/**/*.cpp` → `xvfb-run … ctest` |
| Test environment | `SDL_VIDEO_DRIVER=x11`, `SDL_AUDIO_DRIVER=dummy`, `LIBGL_ALWAYS_SOFTWARE=1`, inside a virtual X display |
| Success | Build passes, clang-tidy reports no errors, all CTest tests pass |

**Not checked by CI:** `clang-format` (run `clang-format --dry-run --Werror` locally), `game_tests`, and pull requests into `phase3` branches (add them to `branches:` when needed).

<a id="clang-format"></a>
### `.clang-format`

LLVM style, 4-space indent, no tabs, 100-column limit, `int* p` pointer style, braces on the same line, no one-line functions, includes sorted. Format with `clang-format -i <files>`.

<a id="clang-tidy"></a>
### `.clang-tidy`

Enables `bugprone-*`, `performance-*`, `modernize-use-nullptr`, `modernize-use-override` and `readability-braces-around-statements`. Warnings are **not** errors (`WarningsAsErrors: ''`). Locally on macOS it may fail with system-header errors, so rely on CI.

<a id="assets"></a>
### `assets/`

| File | Format | Used by | If missing |
| --- | --- | --- | --- |
| `test.bmp` | BMP | [`initializePlatform`](code/platform.md#initializeplatform) (from the executable's folder); [`engine`](code/engine.md#engine) entities 1–2 (from the working directory) | Start-up fails, or `engine()` throws |
| `anim_sheet.bmp` | 128×32 BMP, 24-bit, 4 frames of 32×32 side by side (red, orange, teal, blue, with 1–4 white dots) | [`engine`](code/engine.md#engine) entity 3 + [AnimationComponent](code/animation-component.md) | `engine()` throws |

Only **BMP** is supported (`SDL_LoadBMP`).

## What about `build/`?

`build/` is the **generated** CMake folder: the cache, downloaded SDL/googletest sources (`_deps/`), object files, `compile_commands.json`, and executables in `build/bin/` (`game_engine`, `engine_tests`, `game_tests`, plus a copy of `assets/`). It's ignored by Git. Delete it and reconfigure if things get weird.

## Environment & build quick reference

**Prerequisites:** C++20 compiler, CMake ≥ 3.20, Git, internet access for the first configure. Linux also needs SDL's dev packages (see `ci.yml`).

```sh
cmake -S . -B build                 # configure
cmake --build build                 # build
ctest --test-dir build --output-on-failure
./build/bin/game_tests              # not in ctest
./build/bin/game_engine             # run FROM THE REPO ROOT (relative asset paths)
```

**Next:** [Architecture](architecture/index.md) · [Test index](tests/index.md)
