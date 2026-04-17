#include "Utils.h"



Utils::Utils() : _renderer(NULL) {}

Utils::Utils(SDL_Renderer *renderer)
: _renderer(renderer) {}

SDL_Texture* Utils::loadTexture(const char *file)
{
	SDL_Texture *img = IMG_LoadTexture(_renderer, file);
	if (!img) {
		SDL_Log("Couldn't load texture: %s\n", SDL_GetError());
	}
	return img;
}