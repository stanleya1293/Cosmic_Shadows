#include <iostream>
#include <SDL2/SDL.h>

const int screenH = 700;
const int screenW = 1000;

int main(int argc, char* argv[]) {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cout << "Something went wrong when initializing";
    }
    SDL_Window* gameWin = SDL_CreateWindow("Cosmic Shadows", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenW, screenH, SDL_WINDOW_RESIZABLE);
    SDL_Renderer* gameRen = SDL_CreateRenderer(gameWin, -1, SDL_RENDERER_ACCELERATED);
    SDL_Event* event;
    bool gameRunning = 1;
    while (gameRunning == 1) {
        SDL_PollEvent(event);
        if (event->type == SDL_WINDOWEVENT) {
            if (event->window.event == SDL_WINDOWEVENT_LEAVE) {
                gameRunning = 0;
            }
        }
        
    }
    return 0;
}