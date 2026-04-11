#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <stdexcept>

#include "RenderWindow.hpp"






RenderWindow::RenderWindow(const char *title, int width, int height, SDL_WindowFlags window_flags)
: window(nullptr), renderer(nullptr)
{
	if (!SDL_CreateWindowAndRenderer(title, width, height, window_flags, &window, &renderer)) {
		throw std::runtime_error(SDL_GetError());
	}
}

void RenderWindow::cleanUp()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void RenderWindow::clearRenderer()
{
	SDL_RenderClear(renderer);
}

void RenderWindow::setRendererColorFloat(float r, float g, float b, float a)
{
	SDL_SetRenderDrawColorFloat(renderer, r, g, b, a);
}

void RenderWindow::render(SDL_Texture *texture, const SDL_FRect *srcrect, const SDL_FRect *dstrect)
{
	SDL_RenderTexture(renderer, texture, srcrect, dstrect);
}

void RenderWindow::renderScreen()
{
	SDL_RenderPresent(renderer);
}

SDL_Texture* RenderWindow::loadTexture(const char *file)
{
	SDL_Texture *texture = NULL;
	texture = IMG_LoadTexture(renderer, file);
	if (!texture) SDL_Log("Couldn't load texture: %s\n", SDL_GetError());
	return texture;
}