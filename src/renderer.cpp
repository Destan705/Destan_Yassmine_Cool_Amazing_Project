#include "renderer.h"
#include "logger.h"
#include <iostream>
#include <stdexcept>
#include <string>

Renderer::Renderer(SDL_Window* window) {
    renderer = SDL_CreateRenderer(window, nullptr);
    if (renderer == nullptr) {
        throw std::runtime_error(std::string("Renderer error: ") + std::string(SDL_GetError()));
    }
    logMessage(logger_level::Info, "Renderer is initialized");
    SDL_SetRenderVSync(renderer, 1);
}
Renderer::~Renderer() {
    if (texture != nullptr) {
        SDL_DestroyTexture(texture);
        texture = nullptr;
    }
    SDL_DestroyRenderer(renderer);
}

void Renderer::Present() {
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

void Renderer::LoadTexture(const char* filePath) {
    if (texture != nullptr) {
        SDL_DestroyTexture(texture);
        texture = nullptr;
    }
    // Load the BMP image into an SDL_Surface
    SDL_Surface* surface = SDL_LoadBMP(filePath);

    if (surface == nullptr) {
        throw std::runtime_error(std::string("Failed to load texture:") +
                                std::string(SDL_GetError()) + std::string(" File: ") +
                                std::string(filePath));
    }
    // Create a texture from the surface
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    // free the surface
    SDL_DestroySurface(surface);

    // Check if the texture was created successfully
    if (texture == nullptr) {
        throw std::runtime_error(std::string("Failed to create texture:") +
                                std::string(SDL_GetError()) + std::string(" File: ") +
                                std::string(filePath));
    }
}

void Renderer::DrawTexture(const Bounds& bounds) {
    // TODO: warn once via logger (SCRUM-42)
    if (texture == nullptr) {
        return;
    }

    SDL_FRect rect;

    rect.x = bounds.x;
    rect.y = bounds.y;
    rect.w = bounds.w;
    rect.h = bounds.h;

    SDL_RenderTexture(renderer, texture, nullptr, &rect);
}