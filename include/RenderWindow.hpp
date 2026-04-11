

#pragma once
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>


class RenderWindow {
public:
	RenderWindow(const char* title, int width, int height, SDL_WindowFlags window_flags);
	void cleanUp();
	void clearRenderer();
	void setRendererColorFloat(float r, float g, float b, float a);
	void render(SDL_Texture *texture, const SDL_FRect *srcrect, const SDL_FRect *dstrect);
	void renderScreen();
	SDL_Texture* loadTexture(const char *file);
private:
	SDL_Window *window;
	SDL_Renderer *renderer;
};
