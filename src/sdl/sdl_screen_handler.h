#ifndef _SDL_SCREEN_HANDLER_H_
#define _SDL_SCREEN_HANDLER_H_

#include <string>
#include <iostream>
#include <SDL.h>
#include "datatypes/size.h"
#include "singleton/singleton.h"

class SDL_ScreenHandler : public UnCopyable {
public:
    bool Initialize(std::string windowName, Size windowSize);
    void SetBackBufferColor(SDL_Color color);
    void Flip();
    SDL_Renderer *GetRenderer() { return m_Renderer; }

    ~SDL_ScreenHandler();

private:
    SDL_Window *m_Window = nullptr;
    SDL_Renderer *m_Renderer = nullptr;
    SDL_Color m_BackBufferColor;
    friend class Singleton<SDL_ScreenHandler>;
    SDL_ScreenHandler() {}
};

typedef Singleton<SDL_ScreenHandler> TheSDLScreenHandler;

#endif /* _SDL_SCREEN_HANDLER_H_ */
