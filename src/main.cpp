#include <SDL3/SDL.h>
#include <iostream>

int main() {
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        std::cerr << "SDL_Init failed: " << SDL_GetError() << std::endl;
        return 1;
    }

    std::cout << "SDL3 initialized successfully!" << std::endl;

    SDL_Quit();
    return 0;
}