#ifndef _SDL_TIMER_H_
#define _SDL_TIMER_H_

#include <SDL.h>

class SDL_Timer {
public:
    static float GetDT();

private:
    static unsigned int m_OldTick;
    static unsigned int m_CurrentTick;

    friend class SDL_GameStateManager;
    static void UpdateTimer();
};

#endif /* _SDL_TIMER_H_ */
