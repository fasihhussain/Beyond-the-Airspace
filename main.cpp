
#include "Game.h"
#include "TextureManager.h"

Game *game = nullptr;

int main(int argc, char *argv[])
{
	SDL_Rect src, dest;

	src.x = 0;
	src.y = 0;
	src.w = 1280;
	src.h = 1080;

	dest.x = 0;
	dest.y = 0;
	dest.w = 1280;
	dest.h = 720;

	const int fps = 60;
	const int frameDelay = 1000 / fps;

	Uint32 frameStart;
	int frameTime;

	game = new Game();
	game->init("Aasman ki Unchaiyoun Me", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, false);

	while (game->running())
	{
		frameStart = SDL_GetTicks();

		game->handleEvents();
		game->update();
		game->render();

		frameTime = SDL_GetTicks() - frameStart;
		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}
	}

	game->clean();

	return 0;
}