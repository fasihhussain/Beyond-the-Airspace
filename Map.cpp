#include "Map.h"
#include "TextureManager.h"

int lvl1[10] = {0,0,0,0,0,0,0,0,0,0};

Map::Map()
{
    sky = TextureManager::LoadTexture("assets/background.png");

    LoadMap(lvl1);
    src.x = src.y = 0;
    src.w = 1280;
    src.h = 720;
    dest.w = 1280;
    dest.h = 720;

    dest.x = dest.y = 0;
}

void Map::LoadMap(int arr[10])
{
    for (int i=0;i<10;i++)
    {
        map[i] = arr[i];
    }
}

void Map::DrawMap()
{   
    int type;
    for (int i=0;i<10;i++)
    {
        type = map[i];
        dest.x = i*1280;

        switch (type)
        {
        case 0:
            TextureManager::Draw(sky,src,dest);
            break;
        default:
            break;
        }
    }
}