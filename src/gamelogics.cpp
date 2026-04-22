#include "GameLogics.h"

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>


GameLogics::GameLogics() {}

GameLogics::~GameLogics()
{
	//
}

void GameLogics::drawCircle(SDL_Renderer *renderer, int x, int y, int radius)
{
	for (int dy = -radius; dy <= radius; ++dy) {
		int dx = SDL_sqrt(radius * radius - dy * dy);
		float color = (float)SDL_abs(dy) / radius / 2;
		SDL_SetRenderDrawColorFloat(renderer, color, color, color, 1.0f);
		SDL_RenderLine(renderer, x - dx, y + dy, x + dx, y + dy);
	}
}

void GameLogics::update(Game *gg)
{
	//
}

void GameLogics::render(SDL_Renderer *renderer)
{
	drawCircle(renderer, 200.0f, 200.0f, 100);
}