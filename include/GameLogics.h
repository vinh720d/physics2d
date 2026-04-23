#ifndef GAMELOGICS_H
#define GAMELOGICS_H

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <vector>

#include "Game.h"

class GameLogics
{
public:
	GameLogics();
	~GameLogics();
	void addPoint(SDL_FPoint point);
	void update(Game *gg);
	void render(SDL_Renderer *renderer);
private:
	std::vector<SDL_FPoint> points;
	std::vector<SDL_Vertex> vert;
	std::vector<int> indices;
};

#endif