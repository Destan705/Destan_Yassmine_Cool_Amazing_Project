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

bool running=true;
Color BgColor;// White background
Color rectColor{255, 0, 0, 255}; // Red rectangle
Bounds rectBounds{100.0f, 100.0f, 200.0f, 150.0f}; // Rectangle position and size
SDL_Event event;

    while(running==true){
     // Check for events (like closing the window)
    while(SDL_PollEvent(&event)){
         if(event.type==SDL_EVENT_QUIT){
            running=false;
        }
    }
    renderer.ClearScreen(BgColor);
    renderer.DrawFilledRect(rectColor, rectBounds);
    renderer.Present();
       
    }
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