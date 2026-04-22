#ifndef GAMELOGICS_H
#define GAMELOGICS_H

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

#include "Game.h"

class GameLogics
{
public:
	GameLogics();
	~GameLogics();
	void drawCircle(SDL_Renderer *renderer, int x, int y, int radius);
	void update(Game *gg);
	void render(SDL_Renderer *renderer);
private:
	//
	
};

#endif