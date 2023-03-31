#include "keyboard.h"

KeyboardState Keyboard::m_State;

KeyboardState &Keyboard::GetState() {
    return m_State;
}

void Keyboard::HandleEvent(SDL_KeyboardEvent *keyEvent) {
    switch (keyEvent->type) {
    case SDL_KEYDOWN:
        m_State.m_KeyStates[(Keys)(keyEvent->keysym.sym)] = KeyState::Down;
        break;
    case SDL_KEYUP:
        m_State.m_KeyStates[(Keys)(keyEvent->keysym.sym)] = KeyState::Up;
        break;
    }
}
