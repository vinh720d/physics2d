#include "GameLogics.h"

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>


GameLogics::GameLogics() {}

void GameLogics::update(Game *gg)
{
	int scr_w, scr_h;
	SDL_GetWindowSize(gg->get_window(), &scr_w, &scr_h);
	x = (scr_w - w) / 2;
	y = (scr_h - h) / 2;
}

void GameLogics::render(SDL_Renderer *renderer)
{
	for (float i = 0; i < h; ++i) {
		for (float j = 0; j < w; ++j) {
			SDL_SetRenderDrawColorFloat(renderer, j / w, 0.0f, i / h, 1.0f);
			SDL_RenderPoint(renderer, x + j, y + i);
		}
	}
}