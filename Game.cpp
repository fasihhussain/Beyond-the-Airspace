#include "Game.h"
#include "TextureManager.h"
#include "Vector2D.h"
#include "Collision.h"
#include "ECS/ECS.cpp"
#include "Definitions.h"
#include "AssetManager.h"

SDL_Event Game::event;
SDL_Renderer *Game::renderer = nullptr;
std::vector<ColliderComponent *> Game::colliders;

AssetManager *Game::assets = new AssetManager(&manager);
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

        assets->AddTexture("player", "assets/player_plane.png");
        assets->AddTexture("bullet", "assets/Bullet_3.png");

        map = new Map();

        bg.Load();
        //bg.Draw();

        player.addComponent<TransformComponent>(0.0f, 0.0f, 250, 250, 1);
        player.addComponent<SpriteComponent>("player", true);
        player.addComponent<KeyboardController>();
        player.addComponent<ColliderComponent>("player");
        player.addGroup(groupPlayers);

        assets->CreateProjectile(Vector2D(player.getComponent<TransformComponent>().position.x + 235, player.getComponent<TransformComponent>().position.y + 110), Vector2D(2, 0), 300, 1, "bullet");

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

auto &tiles(manager.getGroup(Game::groupMap));
auto &players(manager.getGroup(Game::groupPlayers));
auto &enemies(manager.getGroup(Game::groupEnemies));
auto &bullets(manager.getGroup(Game::groupBullets));

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

    //for (auto &b : bullets)
    //{
    //if (Collision::AABB(player.getComponent<ColliderComponent>().collider, b->getComponent<ColliderComponent>().collider))
    //{
    //std::cout << "Bullet hit player" << std::endl;
    //b->destroy();
    //}
    //}
}

void Game::render()
{
    SDL_RenderClear(renderer);

    bg.Draw();

    for (auto &t : tiles)
    {
        t->draw();
    }
    for (auto &p : players)
    {
        p->draw();
    }
    for (auto &e : enemies)
    {
        e->draw();
    }

    for (auto &b : bullets)
    {
        b->draw();
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

    if (Game::event.type == SDL_KEYDOWN)
    {
        switch (Game::event.key.keysym.sym)
        {
        case SDLK_SPACE:
            assets->CreateProjectile(Vector2D(player.getComponent<TransformComponent>().position.x + 235, player.getComponent<TransformComponent>().position.y + 110), Vector2D(2, 0), 300, 1, "bullet");

        default:
            break;
        }
    }
}

void Game::AddTile(int id, int x, int y)
{
    auto &tile(manager.addEntity());
    tile.addComponent<TileComponent>(x, y, 32, 32, id);
    tile.addGroup(groupColliders);
}