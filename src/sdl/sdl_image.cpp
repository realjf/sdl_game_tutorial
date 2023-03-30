#include "sdl_image.h"
#include "sdl_screen_handler.h"

bool SDL_Image::Load(const std::string &File) {
    m_Texture = IMG_LoadTexture(TheSDLScreenHandler::Pointer()->GetRenderer(), File.c_str());
    if (!m_Texture) {

        return false;
    }
    SDL_QueryTexture(m_Texture, NULL, NULL, &m_TextureSize.Width, &m_TextureSize.Height);
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
