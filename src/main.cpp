#include <stdio.h> /* printf and fprintf */

#ifdef _WIN32
#include <SDL.h> /* Windows-specific SDL2 library */
#else
#include <SDL.h> /* macOS- and GNU/Linux-specific */
#endif

#include "singleton/singleton.h"
#include "state/igame_state.h"
#include "state/game_state_manager.h"
#include <iostream>
#include "datatypes/size.h"

class TestClass : public IGameState {
public:
    int num = 0;

    virtual void Update() override {
        num++;
    }

    virtual void Draw() override {
        std::cout << num << std::endl;
    }

    virtual void DeInitialize() override {}

    virtual void Initialize() override {}

private:
    TestClass() {}
    friend Singleton<TestClass>;
};

typedef Singleton<TestClass> TheTestClass;

/* Sets constants */
#define WIDTH 800
#define HEIGHT 600
#define DELAY 3000

int main(int argc, char **argv) {
    GameStateManager *gsm = TheGameStateManager::Pointer();

    gsm->SetState(TheTestClass::Pointer());
    gsm->Run();

    Size test(10, 12);
    SizeF test2(test);

    SizeF test3 = test + test2;

    /* Initialises data */
    SDL_Window *window = NULL;

    /*
     * Initialises the SDL video subsystem (as well as the events subsystem).
     * Returns 0 on success or a negative error code on failure using SDL_GetError().
     */
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        fprintf(stderr, "SDL failed to initialise: %s\n", SDL_GetError());
        return 1;
    }

    /* Creates a SDL window */
    window = SDL_CreateWindow("SDL Example",           /* Title of the SDL window */
                              SDL_WINDOWPOS_UNDEFINED, /* Position x of the window */
                              SDL_WINDOWPOS_UNDEFINED, /* Position y of the window */
                              WIDTH,                   /* Width of the window in pixels */
                              HEIGHT,                  /* Height of the window in pixels */
                              0);                      /* Additional flag(s) */

    /* Checks if window has been created; if not, exits program */
    if (window == NULL) {
        fprintf(stderr, "SDL window failed to initialise: %s\n", SDL_GetError());
        return 1;
    }

    /* Pauses all SDL subsystems for a variable amount of milliseconds */
    SDL_Delay(DELAY);

    /* Frees memory */
    SDL_DestroyWindow(window);

    /* Shuts down all SDL subsystems */
    SDL_Quit();

    return 0;
}
