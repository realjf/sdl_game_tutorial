#ifndef _GAME_STATE_MANAGER_H_
#define _GAME_STATE_MANAGER_H_

#include "singleton/singleton.h"
#include "igame_state.h"

class GameStateManager : public UnCopyable {
public:
    IGameState *GetState() {
        return m_CurrentState;
    }

    void SetState(IGameState *gs);

    virtual void Run();

    virtual void Update();

    virtual void Draw();

protected:
    IGameState *m_CurrentState = nullptr;

    GameStateManager() {}
    friend Singleton<GameStateManager>;
};

typedef Singleton<GameStateManager> TheGameStateManager;

#endif /* _GAME_STATE_MANAGER_H_ */
