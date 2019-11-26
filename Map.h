#pragma once
#include "Game.h"

class Map
{
    public:
    Map();
    ~Map();

    void LoadMap(int arr[10]);

    void DrawMap();

    private:

    SDL_Rect src,dest;
    SDL_Texture* sky;
    SDL_Texture* rock;
    int map[10];
};