#include "Game.h"
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <cstddef>

#include "Entity.h"


Game::Game() : _window(nullptr), _renderer(nullptr) {}

Game::~Game()
{
	SDL_DestroyRenderer(_renderer);
	SDL_DestroyWindow(_window);
	SDL_Quit();
}

SDL_Keycode keys;
Entity player;

void Game::init(const char *title, int width, int height, SDL_WindowFlags window_flags)
{
	if (!SDL_Init(SDL_INIT_VIDEO)) {
		SDL_Log("Couldn't init SDL: %s\n", SDL_GetError());
	}

	if (!SDL_CreateWindowAndRenderer(title, width, height, window_flags, &_window, &_renderer)) {
		SDL_Log("Couldn't create window/renderer: %s\n", SDL_GetError());
	}
	running = true;
	player = Entity(loadTexture("./res/the_girl.png"), {100.0f, 100.0f, 128.0f, 128.0f});
	keys = {0};
}

SDL_Texture* Game::loadTexture(const char *file)
{
	SDL_Texture *img = IMG_LoadTexture(_renderer, file);
	if (!img) {
		SDL_Log("Couldn't load texture: %s\n", SDL_GetError());
	}
	return img;
}

void Game::handle_event()
{
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_EVENT_QUIT) {
			running = false;
		}
		keys = event.key.key;
	}
}

void Game::update()
{
	if (keys == SDLK_DOWN) player.move(0.0f, 5.0f);
	else if (keys == SDLK_UP) player.move(0.0f, -5.0f);
	if (keys == SDLK_RIGHT) player.move(5.0f, 0.0f);
	else if (keys == SDLK_LEFT) player.move(-5.0f, 0.0f);
}

void Game::render()
{
	SDL_SetRenderDrawColor(_renderer, 255, 255, 255, 255);
	SDL_RenderClear(_renderer);
	SDL_RenderTexture(_renderer, player.get_img(), NULL, player.get_dst());
	SDL_RenderPresent(_renderer);
}