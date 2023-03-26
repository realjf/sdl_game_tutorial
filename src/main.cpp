#include <SDL.h>
#include <stdio.h>

int main(int argc, char **argv) {

    SDL_Window* window;

    SDL_Init(SDL_INIT_VIDEO);

    window = SDL_CreateWindow(
        "An SDL2 window",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        640,
        480,
        SDL_WINDOW_OPENGL
    );

    if (window == NULL) {
        printf("Could not create window: %d\n", SDL_GetError());
        return 1;
    }


}
