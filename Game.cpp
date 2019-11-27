#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Map.h"
#include"ECS.h"
#include "Component.h"
SDL_Texture *playerTx;
SDL_Rect srcR, destR;
GameObject *player;
Map* map;

SDL_Renderer* Game::renderer = nullptr;
Manager manager;
auto& newPlayer(manager.addEntity());
Game::Game() {}

Game::~Game() {}

void Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    int flags = 0;

    if (fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        std::cout << "Subsystems Initialised..." << std::endl;

        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

        if (window)
        {
            std::cout << "Windows created!" << std::endl;
        }

        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer)
        {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            std::cout << "Renderer Created" << std::endl;
        }
        isRunning = true;

        player = new GameObject("assets/plane.png", 0, 0);
        map = new Map();
        newPlayer.addcomponent<PositionComponent>();
        newPlayer.getComponent<PositionComponent>().setPos(500,500);

    }
    // else
    // {
    //     isRunning = false;
    // }
}

void Game::update()
{
    player->Update();
    manager.update();
    std::cout<<newPlayer.getComponent<PositionComponent>().x()<<","<<newPlayer.getComponent<PositionComponent>().y()<<std::endl;
}

void Game::render()
{
    SDL_RenderClear(renderer);
    map ->DrawMap();
    player->Render();
    //this is where we would add stuff to render
    SDL_RenderPresent(renderer);
}

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game Cleaned" << std::endl;
}

void Game::handleEvents()
{
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type)
    {
    case SDL_QUIT:
        isRunning = false;
        break;

    default:
        break;
    }
}
