# Destan & Yassmine's 2D Game Engine

A small 2D game engine built by **Destan and Yassmine** using **C++20 and SDL3**. We're building this project to learn how game engines work, practise software architecture, and collaborate on a C++ codebase.

The project is currently in **Phase 1**, focused on the engine's core foundations.

## Current Features

- Engine initialization, shutdown, and a game loop with input, update, and rendering stages.
- Delta-time calculation for future game updates.
- Keyboard input abstraction for held, newly pressed, and released keys.
- SDL3 window and renderer setup, filled rectangles, and BMP texture loading and rendering.
- Texture and renderer cleanup through RAII.
- Console logging with info, warning, and error levels.
- Automated tests using GoogleTest, plus GitHub Actions for builds, static analysis, and tests.

The current demo opens an 800 × 600 window and displays a red rectangle and a test texture. Close the window to exit. Game logic is still a placeholder.

## Requirements

- A C++20-compatible compiler
- CMake 3.20 or newer
- Git
- A build tool supported by CMake, such as Make, Ninja, or Visual Studio

CMake downloads SDL3 and GoogleTest automatically during configuration, so an internet connection is required for the first build. Linux also requires SDL's system development dependencies; see [the CI workflow](.github/workflows/ci.yml) for the Ubuntu package list.

## Build and Run

Clone the Phase 1 branch:

```sh
git clone --branch phase1 https://github.com/Destan705/Destan_Yassmine_Cool_Amazing_Project.git
cd Destan_Yassmine_Cool_Amazing_Project
```

Configure and build:

```sh
cmake -S . -B build
cmake --build build --config Debug
```

Run on Linux/macOS:

```sh
./build/bin/game_engine
```

Run on Windows with a single-configuration generator, such as MinGW Makefiles or Ninja:

```powershell
.\build\bin\game_engine.exe
```

With a multi-configuration generator, such as Visual Studio, the executable is typically at `build/bin/Debug/game_engine.exe`.

Assets are copied beside the executable during the build. Keep the `assets` folder alongside it when moving the executable.

## Run Tests

```sh
ctest --test-dir build -C Debug --output-on-failure
```

Some tests initialize SDL's window and rendering systems. Headless Linux environments need a virtual display; the CI workflow includes an Xvfb setup.

## Project Structure

| Folder | Contents |
| --- | --- |
| `src/` | Engine, platform, input, rendering, and logging implementations |
| `include/` | Headers and public interfaces |
| `assets/` | Demo assets |
| `tests/` | GoogleTest tests |
| `.github/workflows/` | Continuous integration |

## Collaboration

Development happens on feature branches. Changes are reviewed through pull requests before being merged into `main`.
