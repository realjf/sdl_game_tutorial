#ifndef _SDL_SPRITESHEET_H_
#define _SDL_SPRITESHEET_H_

#include "datatypes/size.h"
#include "datatypes/rectangle2D.h"
#include "sdl_image.h"

class SDL_SpriteSheet : public SDL_Image {
public:
    void SetCellSize(Size cellSize);
    int GetCellWidth();
    int GetCellHeight();

    SDL_Rect TranslateCell(const int cell);
    bool Load(const std::string &file, const Size &cellSize);
    void Draw(const int cell, const Vector2 &location);

private:
    Size m_CellSize;
};

#endif /* _SDL_SPRITESHEET_H_ */
