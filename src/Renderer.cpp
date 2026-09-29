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

void Renderer::Present(){
     SDL_RenderPresent(renderer);


}
void Renderer::ClearScreen(const Color& color) {
    SDL_SetRenderDrawColor(renderer, color.red, color.green, color.blue, color.alpha);
    SDL_RenderClear(renderer);
}

void Renderer::DrawFilledRect(const Color& color, const Bounds& bounds) {
    // Pick the colour to draw with
    SDL_SetRenderDrawColor(renderer, color.red, color.green, color.blue, color.alpha);

    // Convert our Bounds into SDL's rectangle type
    SDL_FRect rect;
    rect.x = bounds.x;
    rect.y = bounds.y;
    rect.w = bounds.w;
    rect.h = bounds.h;

    // Draw it (SDL wants the rectangle's address)
    SDL_RenderFillRect(renderer, &rect);
}