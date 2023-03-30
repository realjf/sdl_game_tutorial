#ifndef _SDL_EVENT_HANDLER_H_
#define _SDL_EVENT_HANDLER_H_

#include "singleton/singleton.h"

class SDL_EventHandler : public UnCopyable {
public:
    void PoolEvents();

private:
    friend Singleton<SDL_EventHandler>;
    SDL_EventHandler() {}
};

typedef Singleton<SDL_EventHandler> TheSDLEventHandler;

#endif /* _SDL_EVENT_HANDLER_H_ */
