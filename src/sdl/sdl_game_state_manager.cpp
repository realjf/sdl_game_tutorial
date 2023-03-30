#include "sdl_game_state_manager.h"
#include "sdl_screen_handler.h"
#include "sdl_event_handler.h"

void SDL_GameStateManager::Update() {

    TheSDLEventHandler::Pointer()->PoolEvents();

    GameStateManager::Update();
}

void SDL_GameStateManager::Draw() {
    GameStateManager::Draw();
    TheSDLScreenHandler::Pointer()->Flip();
}

void SDL_GameStateManager::HandleEvent(SDL_WindowEvent *event) {
}
