#include "GameLogics.h"

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>


GameLogics::GameLogics() {}

void GameLogics::addPoint(SDL_FPoint point)
{
	points.push_back(point);
	SDL_Vertex vt = {
		point, 
		{SDL_randf(), SDL_randf(), SDL_randf(), 1.0f}, 
		{0, 0}
	};
	vert.push_back(vt);
	if (vert.size() >= 3) {
		if (vert.size() == 3)
			indices = {0, 1, 2};
		else {
			indices.push_back(0);
			indices.push_back(vert.size() - 2);
			indices.push_back(vert.size() - 1);
		}
	}

}

GameLogics::~GameLogics()
{
	//
}

void GameLogics::update(Game *gg)
{
	//
}

void GameLogics::render(SDL_Renderer *renderer)
{
	SDL_RenderGeometry(renderer, NULL, vert.data(), vert.size(), indices.data(), indices.size());
}