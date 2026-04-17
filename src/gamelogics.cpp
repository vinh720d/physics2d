#include "GameLogics.h"
#include "SDL3/SDL_render.h"
#include "SDL3/SDL_stdinc.h"

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>


GameLogics::GameLogics() {}

void GameLogics::update(Game *gg)
{
	int w, h;
	SDL_GetWindowSize(gg->get_window(), &w, &h);
	x = (float)w / 2;
	y = (float)h / 2;
}

void GameLogics::render(SDL_Renderer *renderer)
{
	for (int i = 0; i < 360; i ++) {
		float x2, y2;
		x2 = SDL_cos((double)i / 180 * SDL_PI_D) * radius + x;
		y2 = SDL_sin((double)i / 180 * SDL_PI_D) * radius + y;
		SDL_SetRenderDrawColorFloat(renderer, SDL_randf(), SDL_randf(), SDL_randf(), 1.0f);
		SDL_RenderLine(renderer, x, y, x2, y2);
	}
}