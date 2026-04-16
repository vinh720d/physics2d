#ifndef GAME_H
#define GAME_H

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

class Game
{
public:
	Game();
	~Game();
	bool running;
	void init(const char *title, int width, int height, SDL_WindowFlags window_flags);
	SDL_Texture* loadTexture(const char *file);
	void handle_event();
	void update();
	void render();
private:
	SDL_Window *_window;
	SDL_Renderer *_renderer;
};

#endif