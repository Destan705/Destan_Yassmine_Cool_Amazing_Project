#include "Renderer.hpp"
#include <stdexcept>
#include <string>
#include <iostream>

Renderer::Renderer(SDL_Window* window){
renderer=SDL_CreateRenderer(window, nullptr);
 if (renderer == nullptr) {
        throw std::runtime_error(std::string("Renderer error: ")+ std::string(SDL_GetError())) ;
    }
    std::cout << "Renderer is initialized" << std::endl;
    SDL_SetRenderVSync(renderer, 1);
}

Renderer::~Renderer(){
 SDL_DestroyRenderer(renderer);
}