#ifndef _KEYBOARD_H_
#define _KEYBOARD_H_

#include <SDL.h>
#include "keyboard_state.h"

class Keyboard {
public:
    static KeyboardState &GetState();

private:
    static KeyboardState m_State;
    static void HandleEvent(SDL_KeyboardEvent *keyEvent);
    friend class SDL_EventHandler;
};

#endif /* _KEYBOARD_H_ */
