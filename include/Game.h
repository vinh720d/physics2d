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
	void handle_event();
	void update();
	void render();
	SDL_Window* get_window();
	SDL_Renderer* get_renderer();
private:
	SDL_Window *_window;
	SDL_Renderer *_renderer;
};

#endif