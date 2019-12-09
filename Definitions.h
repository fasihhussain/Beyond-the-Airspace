#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "Map.h"
#include "Time.h"
#include "Background.h"
#include "ECS/Components.h"

static SDL_Texture *playerTx;
static SDL_Rect srcR, destR;

static Map *map;
static Background bg;
static Time time;

static Manager manager;
auto &player(manager.addEntity());
