#ifndef _SDL_GAME_STATE_MANAGER_H_
#define _SDL_GAME_STATE_MANAGER_H_

#include <SDL.h>
#include "state/igame_state_manager.h"

class SDL_GameStateManager : public IGameStateManager {
public:
    virtual void Update() override;
    virtual void Draw() override;

private:
    friend Singleton<SDL_GameStateManager>;
    SDL_GameStateManager() {}

    friend class SDL_EventHandler;
    void HandleEvent(SDL_WindowEvent *event);
};

typedef Singleton<SDL_GameStateManager> TheSDLGameStateManager;

#endif /* _SDL_GAME_STATE_MANAGER_H_ */
