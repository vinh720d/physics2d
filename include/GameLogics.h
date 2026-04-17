#ifndef GAMELOGICS_H
#define GAMELOGICS_H

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

#include "Game.h"

class GameLogics
{
public:
	GameLogics();
	void buildGradient(SDL_Renderer *renderer);
	void update(Game *gg);
	void render(SDL_Renderer *renderer);
private:
	float w = 200.0f, h = 200.0f;
	float x, y;
	SDL_Texture *gradientTexture = NULL;
};

#endif