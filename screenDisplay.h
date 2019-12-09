#pragma once
#include "TextureManager.h"

class screenDisplay
{
private:
    SDL_Texture *temp;
    const char *path;
    SDL_Rect src, dest;

public:
    void Load(const char *path);

    void setDimension(int x, int y, int w, int h, int x2, int y2, int w2, int h2);
    void Draw();
};