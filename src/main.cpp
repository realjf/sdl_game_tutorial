
#include <iostream>
#include <stdio.h>
#include <SDL.h>
#include "sdl/sdl_screen_handler.h"
#include "sdl/sdl_game_state_manager.h"
#include "sdl/sdl_image.h"
#include "sdl/sdl_spritesheet.h"

class TestState : public IGameState {
public:
    virtual void Update() override {
    }
    virtual void Draw() override {
        img.Draw(Vector2(40, 40));
        spr.Draw(1, Vector2(40, 40));
    }
    virtual void Initialize() override {
        img.Load("assets/image/boss1.png");
        spr.Load("assets/image/helicopter2.png", Size(128, 55));
    }
    virtual void DeInitialize() override {}

private:
    friend Singleton<TestState>;
    TestState() {}
    SDL_Image img;
    SDL_SpriteSheet spr;
};

typedef Singleton<TestState> TheTestState;

int main(int argc, char **argv) {

    TheSDLScreenHandler::Pointer()->Initialize("SDL GAME", Size(1024, 760));
    TheSDLScreenHandler::Pointer()->SetBackBufferColor(SDL_Color{100, 149, 237, 255});
    TheSDLGameStateManager::Pointer()->SetState(TheTestState::Pointer());
    TheSDLGameStateManager::Pointer()->Run();

    return 0;
}
