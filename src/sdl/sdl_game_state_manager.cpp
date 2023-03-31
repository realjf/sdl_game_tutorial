#include "sdl_game_state_manager.h"
#include "sdl_screen_handler.h"
#include "sdl_event_handler.h"
#include "sdl/sdl_timer.h"

void SDL_GameStateManager::Update() {
    SDL_Timer::UpdateTimer();

    TheSDLEventHandler::Pointer()->PoolEvents();

    GameStateManager::Update();
}

void SDL_GameStateManager::Draw() {
    GameStateManager::Draw();
    TheSDLScreenHandler::Pointer()->Flip();
}

void SDL_GameStateManager::HandleEvent(SDL_WindowEvent *event) {

    switch (event->event) {
    case SDL_WINDOWEVENT_SHOWN:
        SDL_Log("Window %d shown", event->windowID);
        break;
    case SDL_WINDOWEVENT_HIDDEN:
        SDL_Log("Window %d hidden", event->windowID);
        break;
    case SDL_WINDOWEVENT_EXPOSED:
        SDL_Log("Window %d exposed", event->windowID);
        break;
    case SDL_WINDOWEVENT_MOVED:
        SDL_Log("Window %d moved to %d,%d",
                event->windowID, event->data1,
                event->data2);
        break;
    case SDL_WINDOWEVENT_RESIZED:
        SDL_Log("Window %d resized to %dx%d",
                event->windowID, event->data1,
                event->data2);
        break;
    case SDL_WINDOWEVENT_SIZE_CHANGED:
        SDL_Log("Window %d size changed to %dx%d",
                event->windowID, event->data1,
                event->data2);
        break;
    case SDL_WINDOWEVENT_MINIMIZED:
        SDL_Log("Window %d minimized", event->windowID);
        break;
    case SDL_WINDOWEVENT_MAXIMIZED:
        SDL_Log("Window %d maximized", event->windowID);
        break;
    case SDL_WINDOWEVENT_RESTORED:
        SDL_Log("Window %d restored", event->windowID);
        break;
    case SDL_WINDOWEVENT_ENTER:
        SDL_Log("Mouse entered window %d",
                event->windowID);
        break;
    case SDL_WINDOWEVENT_LEAVE:
        SDL_Log("Mouse left window %d", event->windowID);
        break;
    case SDL_WINDOWEVENT_FOCUS_GAINED:
        SDL_Log("Window %d gained keyboard focus",
                event->windowID);
        break;
    case SDL_WINDOWEVENT_FOCUS_LOST:
        SDL_Log("Window %d lost keyboard focus",
                event->windowID);
        break;
    case SDL_WINDOWEVENT_CLOSE:
        SDL_Log("Window %d closed", event->windowID);
        break;
#if SDL_VERSION_ATLEAST(2, 0, 5)
    case SDL_WINDOWEVENT_TAKE_FOCUS:
        SDL_Log("Window %d is offered a focus", event->windowID);
        break;
    case SDL_WINDOWEVENT_HIT_TEST:
        SDL_Log("Window %d has a special hit test", event->windowID);
        break;
#endif
    default:
        SDL_Log("Window %d got unknown event %d",
                event->windowID, event->event);
        break;
    }
}
