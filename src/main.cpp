
#include <iostream>
#include <stdio.h>
#include <SDL.h>
#include "sdl/sdl_screen_handler.h"
#include "sdl/sdl_game_state_manager.h"

class TestState : public IGameState {
public:
    virtual void Update() override {}
    virtual void Draw() override {}
    virtual void Initialize() override {}
    virtual void DeInitialize() override {}

private:
    friend Singleton<TestState>;
    TestState() {}
};

typedef Singleton<TestState> TheTestState;

int main(int argc, char **argv) {

    TheSDLScreenHandler::Pointer()->Initialize("SDL GAME", Size(1024, 760));
    TheSDLScreenHandler::Pointer()->SetBackBufferColor(SDL_Color{100, 149, 237, 255});
    TheSDLGameStateManager::Pointer()->SetState(TheTestState::Pointer());
    TheSDLGameStateManager::Pointer()->Run();

    return 0;
}
