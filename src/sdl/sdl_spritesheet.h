#ifndef _SDL_SPRITESHEET_H_
#define _SDL_SPRITESHEET_H_

#include "datatypes/size.h"
#include "datatypes/rectangle2D.h"
#include "sdl_image.h"

class SDL_SpriteSheet : public SDL_Image {
public:
    void SetCellSize(Size CellSize);
    int GetCellWidth();
    int GetCellHeight();

    SDL_SpriteSheet() {}

    Rectangle TranslateCell(const int Cell);
    bool Load(const std::string &File);
    void Draw(const int Cell, const Vector2 &Location);
};

#endif /* _SDL_SPRITESHEET_H_ */
