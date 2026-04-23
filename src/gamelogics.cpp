#include "GameLogics.h"
#include "SDL3/SDL_mouse.h"
#include "SDL3/SDL_render.h"

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>


GameLogics::GameLogics()
{
	canvas = NULL;
}

GameLogics::~GameLogics()
{
	//
}

void GameLogics::draw_circle(SDL_Renderer *renderer, float x, float y, float radius)
{
	for (float dy = -radius; dy <= radius; ++dy) {
		float dx = SDL_sqrt(radius*radius - dy*dy);
		SDL_RenderLine(renderer, x - dx, y + dy, x + dx, y + dy);
	}
}

void GameLogics::update(Game *gg)
{
	SDL_GetWindowSize(gg->get_window(), &scr_w, &scr_h);
	Uint32 button = SDL_GetMouseState(&x, &y);
	painting = button & SDL_BUTTON_LMASK;
}

void GameLogics::render(SDL_Renderer *renderer)
{
	if (canvas == NULL) {
		canvas = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, scr_w, scr_h);
	}
		popup = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 100, 100);

	SDL_SetRenderTarget(renderer, canvas);
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	if (painting)
		draw_circle(renderer, x, y, radius);
	SDL_SetRenderTarget(renderer, NULL);
	SDL_SetRenderTarget(renderer, popup);
	SDL_FRect src = {x - 5, y - 5, 10, 10};
	SDL_FRect dst = {0, 0, 100, 100};
	SDL_RenderTexture(renderer, canvas, &src, &dst);
	SDL_SetRenderTarget(renderer, NULL);
	SDL_RenderTexture(renderer, canvas, NULL, NULL);
	dst = {x + 10, y, 100, 100};
	SDL_RenderTexture(renderer, popup, NULL, &dst);
}