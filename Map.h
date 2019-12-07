#pragma once
#include <string>
#include <SDL.h>
#include <SDL_image.h>

class Map
{
public:
    Map();
    ~Map();

    void LoadMap(std::string path, int sizeX, int sizeY);
};