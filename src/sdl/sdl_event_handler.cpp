#include "sdl_event_handler.h"
#include <SDL.h>
#include "sdl_game_state_manager.h"
#include "input/keyboard.h"

void SDL_EventHandler::PoolEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_QUIT:
            TheSDLGameStateManager::Pointer()->SetState(nullptr);
            break;
        case SDL_WINDOWEVENT:
            TheSDLGameStateManager::Pointer()->HandleEvent(&event.window);
            break;
        case SDL_KEYDOWN:
        case SDL_KEYUP:
            Keyboard::HandleEvent(&event.key);
            break;
        }
    }
}
