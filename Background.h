#pragma once
#include "TextureManager.h"

class Background
{
private:
    SDL_Rect src, dest;
    const char *path;
    SDL_Texture *temp;

public:
    Background();

    void update();

    void Draw();

    void Load();
};