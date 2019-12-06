#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char *texturesheet, int x, int y)
{
    objTexture = TextureManager::LoadTexture(texturesheet);

    xpos = x;
    ypos = y;
    x_col = 0;
    y_col = 0;
}

void GameObject::Update()
{
    xpos++;
    y_col = 0;
    // ypos++;
    x_col++;
    x_col %= 50;
    xpos %= 1920;
    // if (y_col % 5 != 1)
    // {
    srcRect.h = 258;
    srcRect.w = 258;
    srcRect.x = 258 * (x_col % 5);
    srcRect.y = 258 * y_col;
    // }

    destRect.x = xpos;
    destRect.y = 100;
    destRect.w = 258;
    destRect.h = 258;
}

void GameObject::Render()
{

    SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
}