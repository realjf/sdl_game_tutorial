#ifndef _IGAME_STATE_MANAGER_H_
#define _IGAME_STATE_MANAGER_H_

#include "game_state_manager.h"

class IGameStateManager : public GameStateManager {
public:
    virtual void Update() = 0;
    virtual void Draw() = 0;
};

#endif /* _IGAME_STATE_MANAGER_H_ */
