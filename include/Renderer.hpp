#pragma once
#include <SDL3/SDL.h>


class Renderer{
    public:
    explicit Renderer( SDL_Window* window);// contructor
    ~Renderer();// destructor
    Renderer(const Renderer&) = delete;             // sign #1: no making a new box as a copy
    Renderer& operator=(const Renderer&) = delete;  // sign #2: no turning an old box into a copy   
    
    private:
    SDL_Renderer* renderer=nullptr;
};