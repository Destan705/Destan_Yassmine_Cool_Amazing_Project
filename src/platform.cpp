#include "logger.h"
#include "renderer.h"
#include "render_api.h"
#include <SDL3/SDL.h>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <array>

SDL_Window* window = nullptr;
std::unique_ptr<Renderer> renderer = nullptr;

bool initializePlatform() {
    // Initialize SDL Subsystems
    if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO)) {
        logMessage(logger_level::Error,
                "SDL could not initialize! SDL_Error: " + std::string(SDL_GetError()));
        return false;
    }
    logMessage(logger_level::Info, "SDL3 initialized successfully!");

    // Create a window
    window = SDL_CreateWindow("My SDL3 Window", 800, 600, SDL_WINDOW_OPENGL);

    if (window == nullptr) {
        logMessage(logger_level::Error,
                "Window could not be created! SDL_Error: " + std::string(SDL_GetError()));
        SDL_Quit();
        return false;
    }
    logMessage(logger_level::Info, "Window created successfully!");

    // Open Renderer

    try {
        renderer = std::make_unique<Renderer>(window);
        const char* basePath = SDL_GetBasePath();

        if (basePath == nullptr) {
            throw std::runtime_error(std::string("Could not locate assets! SDL_Error: ") +
                                    SDL_GetError());
        }
        const std::string texturePath = std::string(basePath) + "assets/test.bmp";

        renderer->LoadTexture(texturePath.c_str());

    } catch (const std::runtime_error& e) {
        logMessage(logger_level::Error, e.what());
        renderer.reset();
        SDL_DestroyWindow(window);
        window = nullptr;
        SDL_Quit();
        return false;
    }

    return true;
}


void beginFrame() {
    if (renderer == nullptr) {
        logMessage(logger_level::Warning, "Renderer is not initialized!");
        return;
    }
    // Clear the screen with a black color
    renderer->ClearScreen(Color{0, 0, 0, 255});

}

void drawFilledRect(Color rectColor, Bounds rectBounds){
    // Draw a rectangle in the center of the screen
    renderer->DrawFilledRect(rectColor, rectBounds);
}

void drawTexture(){
    renderer->DrawTexture(Bounds{100.0f, 100.0f, 200.0f, 200.0f});
}

void presentFrame(){
    // Present the rendered frame on the screen
    renderer->Present();
}

void shutdownPlatform() {
    // Destroy the renderer first
    renderer.reset();
    // Destroy the window
    if (window != nullptr) {
        SDL_DestroyWindow(window);
        window = nullptr;
    }
    // Quit SDL subsystems
    logMessage(logger_level::Info, "Engine is shutting down");
    SDL_Quit();
}