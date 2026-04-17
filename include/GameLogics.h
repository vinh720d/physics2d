#ifndef GAMELOGICS_H
#define GAMELOGICS_H

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

#include "Game.h"

class GameLogics
{
public:
	GameLogics();
	void update(Game *gg);
	void render(SDL_Renderer *renderer);
private:
	float radius = 100.0f;
	float x = 0.0f, y = 0.0f;
};

#endif