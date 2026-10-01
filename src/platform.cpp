#include "renderer.h"
#include <SDL3/SDL.h>
#include <iostream>
#include <memory>
#include <stdexcept>

SDL_Window* window = nullptr;
std::unique_ptr<Renderer> renderer = nullptr;

bool initializePlatform() {
    // Initialize SDL Subsystems
    if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO)) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return false;
    }
    std::cout << "SDL3 initialized successfully!" << std::endl;

    // Create a window
    window = SDL_CreateWindow("My SDL3 Window", 800, 600, SDL_WINDOW_OPENGL);

    if (window == nullptr) {
        std::cerr << "Window could not be created! SDL_Error:" << SDL_GetError() << std::endl;
        SDL_Quit();
        return false;
    }
    std::cout << "Window created successfully!" << std::endl;

    // Open Renderer

    try {
        renderer = std::make_unique<Renderer>(window);

    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
        SDL_DestroyWindow(window);
        window = nullptr;
        SDL_Quit();
        return false;
    }

    return true;
}

void renderPlatform() {
    if(renderer == nullptr){
        std::cerr << "Renderer is not initialized!" << std::endl;
        return;
    }
    // Clear the screen with a black color
    renderer->ClearScreen(Color{0, 0, 0, 255});

    // Draw a red rectangle in the center of the screen
    Bounds rectBounds{300.0f, 200.0f, 200.0f, 200.0f};
    renderer->DrawFilledRect(Color{255, 0, 0, 255}, rectBounds);

    // Present the rendered frame on the screen
    renderer->Present();
}

void shutdownPlatform(){
    //Destroy the renderer first
    renderer.reset();
    //Destroy the window
    if(window != nullptr){
    SDL_DestroyWindow(window);
    window = nullptr;
    }
    //Quit SDL subsystems
    std::cout << "Engine is shutdown";
    SDL_Quit();

}