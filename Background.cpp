#include "Background.h"

Background::Background()
{
    src.x = src.y = 0;
    src.w = 320;
    src.h = 180;

    dest.x = dest.y = 0;
    dest.w = 1280;
    dest.h = 720;

    path = "assets/bgstitch2.png";
}

void Background::update()
{
    if (src.x == 320)
    {
        src.x = 0;
    }
    src.x++;
}

void Background::Draw()
{

    temp = TextureManager::LoadTexture(path);

    TextureManager::Draw(temp, src, dest, SDL_FLIP_NONE);
}