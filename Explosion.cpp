#include "Explosion.h"

void Explosion::Load(const char *path)
{
    temp = TextureManager::LoadTexture(path);
}

void Explosion::Draw(SDL_Rect dest)
{

    SDL_Rect src;
    src.x = 790;
    src.y = 290;
    src.w = 1030 - 790;
    src.h = 480 - 290;

    TextureManager::Draw(temp, src, dest, SDL_FLIP_NONE);
}
