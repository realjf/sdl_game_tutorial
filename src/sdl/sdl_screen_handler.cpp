#include "sdl_screen_handler.h"

bool SDL_ScreenHandler::Initialize(std::string windowName, Size windowSize) {
    if (SDL_Init(SDL_INIT_EVERYTHING)) {
        std::cout << "Initializing SDL error: " << SDL_GetError() << std::endl;
        return false;
    }

    m_Window = SDL_CreateWindow(windowName.c_str(), 10, 10, windowSize.Width, windowSize.Height, 0);
    if (m_Window == nullptr) {
        std::cout << "create SDL window error: " << SDL_GetError() << std::endl;
        return false;
    }

    m_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED);
    if (m_Renderer == nullptr) {
        std::cout << "create SDL Renderer error: " << SDL_GetError() << std::endl;
        return false;
    }

    SDL_RenderClear(m_Renderer);

    return true;
}

void SDL_ScreenHandler::SetBackBufferColor(SDL_Color color) {
    SDL_SetRenderDrawColor(m_Renderer, color.r, color.g, color.b, color.a);
}

void SDL_ScreenHandler::Flip() {
    SDL_RenderPresent(m_Renderer);
    SDL_RenderClear(m_Renderer);
}

SDL_ScreenHandler::~SDL_ScreenHandler() {
    SDL_DestroyRenderer(m_Renderer);
    SDL_DestroyWindow(m_Window);
    SDL_Quit();
}
