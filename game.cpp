#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

const int screenH = 700;
const int screenW = 1000;

int main(int argc, char* argv[]) {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cout << "Something went wrong when initializing";
    }
    IMG_Init(IMG_INIT_PNG);
    SDL_Window* gameWin = SDL_CreateWindow("Cosmic Shadows", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenW, screenH, SDL_WINDOW_RESIZABLE);
    SDL_Renderer* gameRen = SDL_CreateRenderer(gameWin, -1, SDL_RENDERER_ACCELERATED);
    SDL_Surface* surface = IMG_Load("pixil-frame-0.png");
    SDL_Texture* smiley = SDL_CreateTextureFromSurface(gameRen, surface);
    SDL_RenderCopy(gameRen, smiley, NULL, NULL);
    SDL_Event* event;
    bool gameRunning = true;
    while (gameRunning == true) {
        SDL_PollEvent(event);
        SDL_RenderPresent(gameRen);
        if (event->type == SDL_WINDOWEVENT) {
            if (event->window.event == SDL_WINDOWEVENT_CLOSE) {
                gameRunning = false;
            }
        }
    }
    SDL_DestroyTexture(smiley);
    SDL_DestroyWindow(gameWin);
    SDL_DestroyRenderer(gameRen);
    SDL_Quit();
    IMG_Quit();

    return 0;
}