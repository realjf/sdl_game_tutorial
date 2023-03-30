#ifndef _IGAME_STATE_H_
#define _IGAME_STATE_H_

#include "singleton/singleton.h"

class IGameState {
public:
    virtual ~IGameState() {}
    // Gets called when the state first gets set
    virtual void Initialize() = 0;

    virtual void Update() = 0;
    virtual void Draw() = 0;

    // Gets called when the state changes
    virtual void DeInitialize() = 0;
};

#endif /* _IGAME_STATE_H_ */
