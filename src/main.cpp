#include <SDL3/SDL.h>
#include <iostream>

int main() {
    // Initializing SDL3
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        std::cerr << "SDL_Init failed: " << SDL_GetError() << std::endl;
        return 1;
    }

    std::cout << "SDL3 initialized successfully!" << std::endl;
    // Open Window
    SDL_Window* window = SDL_CreateWindow("Game Engine", 1000, 1000, SDL_WINDOW_RESIZABLE);
    // Checks whether the window is open
    if (window == nullptr) {
        std::cerr << "Window could not be opened: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }
    std::cout << "Window is open" << std::endl;
    // Open Renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, nullptr);
    // Checks the Renderer
    if (renderer == nullptr) {
        std::cerr << "Renderer could not be initialized: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }
    std::cout << "Renderer is initialized" << std::endl;

    SDL_SetRenderVSync(renderer, 1);

    // Clean-up Path- destroys both the renderer and the window
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();
    return 0;
}