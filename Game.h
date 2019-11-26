#ifndef Game_h
#define Game_h

#ifdef __APPLE__
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#else
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#endif

class Game
{
public:
   Game();
   ~Game();

   void init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen);
   void handleEvents();
   void update();
   void render();
   void clean();
   static SDL_Renderer* renderer;

   bool running() { return isRunning; }

private:
   int cnt = 0;
   bool isRunning;
   SDL_Window *window;
};

#endif // Game_Class_h
