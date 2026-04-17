#include "GameLogics.h"
#include "SDL3/SDL_pixels.h"
#include "SDL3/SDL_render.h"

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <cstddef>
#include <vector>


GameLogics::GameLogics() {}

void GameLogics::buildGradient(SDL_Renderer *renderer)
{
	if (gradientTexture) return;

	gradientTexture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, (int)w, (int)h);

	std::vector<Uint32> pixels((int)w * (int)h);
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			Uint8 r = (Uint8)(255 * j / w);
			Uint8 g = 0;
			Uint8 b = (Uint8)(255 * i / h);
			Uint8 a = 255;
			pixels[i * (int)w + j] = (r << 24) | (g << 16) | (b << 8) | a;
		}
	}
	SDL_UpdateTexture(gradientTexture, NULL, pixels.data(), (int)w * 4);
}

void GameLogics::update(Game *gg)
{
	int scr_w, scr_h;
	SDL_GetWindowSize(gg->get_window(), &scr_w, &scr_h);
	x = (scr_w - w) / 2;
	y = (scr_h - h) / 2;
}

void GameLogics::render(SDL_Renderer *renderer)
{
	buildGradient(renderer);
	SDL_FRect dst = {x, y, w, h};
	SDL_RenderTexture(renderer, gradientTexture, NULL, &dst);
}