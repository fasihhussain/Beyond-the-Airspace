#pragma once

#include "TextureManager.h"

class Explosion
{

private:
    const char *path;
    SDL_Texture *temp;

public:
    void Load(const char *path);

    void Draw(SDL_Rect dest);
};