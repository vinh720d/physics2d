#include "Game.h"
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

#include "SDL3/SDL_events.h"
#include "SDL3/SDL_keycode.h"
#include "Utils.h"
#include "GameLogics.h"


Utils uu;
GameLogics gl;
SDL_Keycode keys;




Game::Game() : _window(nullptr), _renderer(nullptr) {}

Game::~Game()
{
	SDL_DestroyRenderer(_renderer);
	SDL_DestroyWindow(_window);
	SDL_Quit();
}

void Game::init(const char *title, int width, int height, SDL_WindowFlags window_flags)
{
	if (!SDL_Init(SDL_INIT_VIDEO)) {
		SDL_Log("Couldn't init SDL: %s\n", SDL_GetError());
	}

	if (!SDL_CreateWindowAndRenderer(title, width, height, window_flags, &_window, &_renderer)) {
		SDL_Log("Couldn't create window/renderer: %s\n", SDL_GetError());
	}
	running = true;
}

void Game::handle_event()
{
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_EVENT_MOUSE_BUTTON_DOWN) {
			//
		}
		if (event.type == SDL_EVENT_QUIT) {
			running = false;
		}
		if (event.type == SDL_EVENT_KEY_DOWN) {
			keys = event.key.key;
			if (event.key.key == SDLK_ESCAPE) {
				running = false;
			}
		}
		else if (event.type == SDL_EVENT_KEY_UP)
			keys = 0;
	}
}

void Game::update()
{
	gl.update(this);
}

void Game::render()
{
	SDL_SetRenderDrawColor(_renderer, 36, 33, 33, 255);
	SDL_RenderClear(_renderer);
	gl.render(_renderer);
	SDL_RenderPresent(_renderer);
}

SDL_Window* Game::get_window()
{
	return _window;
}

SDL_Renderer* Game::get_renderer()
{
	return _renderer;
}