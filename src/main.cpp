#include <SDL3/SDL.h>
#include <iostream>
#include "Renderer.hpp"
#include <stdexcept>

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
//when your renderer constructor fails, it throws an exeception.
   try{
    // Open Renderer
    Renderer renderer(window);
   }catch(const std::runtime_error& e){
    std::cerr << e.what()<< std::endl;
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 1;}
   

    // Clean-up Path- destroys both the renderer and the window
    SDL_DestroyWindow(window);

    SDL_Quit();
    return 0;
}