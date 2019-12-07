#include "Game.h"
#include "TextureManager.h"
#include "Map.h"
#include "ECS/Components.h"
#include "Vector2D.h"
#include "Collision.h"
#include "ECS/ECS.cpp"
#include "Background.h"
#include "Time.h"

SDL_Texture *playerTx;
SDL_Rect srcR, destR;

SDL_Event Game::event;

Map *map;
Background bg;
Time time;

SDL_Renderer *Game::renderer = nullptr;

std::vector<ColliderComponent *> Game::colliders;

Manager manager;
auto &player(manager.addEntity());
auto &enemy(manager.addEntity());

enum groupLabels : std::size_t
{
    groupMap,
    groupPlayers,
    groupEnemies,
    groupColliders
};

Game::Game()
{
}

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

        map = new Map();

        bg.Load();
        //bg.Draw();

        player.addComponent<TransformComponent>(0.0f, 0.0f, 250, 250, 1);
        player.addComponent<SpriteComponent>("assets/player_plane.png", true);
        player.addComponent<KeyboardController>();
        player.addComponent<ColliderComponent>("player");
        player.addGroup(groupPlayers);

        //enemy.addComponent<TransformComponent>(500.0f, 0.0f, 200, 252, 1);
        //enemy.addComponent<SpriteComponent>("assets/enemy_plane.png");
        //enemy.addComponent<ColliderComponent>("enemy");
        //enemy.addGroup(groupEnemies);
    }
    else
    {
        isRunning = false;
    }
}

void Game::update()
{
    manager.refresh();
    manager.update();
    bg.update();

    if (time.check_Time(60000))
    {
        std::cout << "Level Pass" << std::endl;

        Game::isRunning = false;
    }
    for (auto cc : colliders)
    {
        Collision::AABB(player.getComponent<ColliderComponent>(), *cc);
    }
}

auto &tiles(manager.getGroup(groupMap));
auto &players(manager.getGroup(groupPlayers));
auto &enemies(manager.getGroup(groupEnemies));

void Game::render()
{
    SDL_RenderClear(renderer);

    bg.Draw();

    for (auto t : tiles)
    {
        t->draw();
    }
    for (auto p : players)
    {
        p->draw();
    }
    for (auto e : enemies)
    {
        e->draw();
    }

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

void Game::AddTile(int id, int x, int y)
{
    auto &tile(manager.addEntity());
    tile.addComponent<TileComponent>(x, y, 32, 32, id);
    tile.addGroup(groupColliders);
}