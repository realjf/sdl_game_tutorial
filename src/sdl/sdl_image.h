#ifndef _SDL_IMAGE_H_
#define _SDL_IMAGE_H_

#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include "datatypes/vector2.h"
#include "datatypes/size.h"

class SDL_Image {
public:
    virtual bool Load(const std::string &File);
    virtual void Draw(const Vector2 &Location);
    virtual ~SDL_Image();

protected:
    SDL_Texture *m_Texture = nullptr;
    Size m_TextureSize;
};

#endif /* _SDL_IMAGE_H_ */
