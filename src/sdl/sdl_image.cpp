#include "sdl_image.h"
#include "sdl_screen_handler.h"

bool SDL_Image::Load(const std::string &File) {
    SDL_Surface *surface = IMG_Load(File.c_str());
    if (surface == nullptr) {
        std::cout << "Error loading image: " << SDL_GetError() << std::endl;
        return false;
    }
    m_Texture = SDL_CreateTextureFromSurface(TheSDLScreenHandler::Pointer()->GetRenderer(), surface);
    SDL_FreeSurface(surface);
    if (m_Texture == nullptr) {
        std::cout << "Couldn't load texture: " << SDL_GetError() << std::endl;
        return false;
    }

    SDL_QueryTexture(m_Texture, NULL, NULL, &m_TextureSize.Width, &m_TextureSize.Height);
    std::cout << "load image successfully" << std::endl;
    return true;
}

void SDL_Image::Draw(const Vector2 &Location) {

    SDL_Rect destination;
    destination.x = Location.X;
    destination.y = Location.Y;
    destination.w = m_TextureSize.Width;
    destination.h = m_TextureSize.Height;
    SDL_RenderCopy(TheSDLScreenHandler::Pointer()->GetRenderer(), m_Texture, NULL, &destination);
}

SDL_Image::~SDL_Image() {
}
