#include "SDL3/SDL_events.h"
#include "SDL3/SDL_init.h"
#include "SDL3/SDL_rect.h"
#include "SDL3/SDL_render.h"
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <iostream>


const int WIDTH = 700, HEIGHT = 500;
static SDL_Window *window = NULL;
static SDL_Renderer *renderer = NULL;
bool RUNNING = true;

float x = 100.0f;
SDL_FRect dst = {x, 100.0f, 300.0f, 300.0f};
SDL_Texture *img = NULL;


struct Clock
{
	Uint64 last;
	Clock() : last(SDL_GetTicks()) {}
	void tick(int fps)
	{
		float frametime = 1000.0 / fps;
		Uint64 elapsed = SDL_GetTicks() - last;
		if (elapsed < frametime)
		{
			SDL_Delay((Uint32)(frametime - elapsed));
		}
		last = SDL_GetTicks();
	}
} clock1, clock2;

int render_thread(void *data)
{
	while (RUNNING) {
		SDL_RenderClear(renderer);

		SDL_SetRenderDrawColorFloat(renderer, 1.0f, 1.0f, 1.0f, 1.0f);

		SDL_RenderTexture(renderer, img, NULL, &dst);

		SDL_RenderPresent(renderer);

		clock2.tick(60);
	}
	return 0;
}


int main(int argc, const char *argv[])
{
	if (!SDL_Init(SDL_INIT_VIDEO)) {
		std::cout << "Couldn't init SDL: " << SDL_GetError() << std::endl;
		return 1;
	}

	if (!SDL_CreateWindowAndRenderer("First SDL app!", WIDTH, HEIGHT, SDL_WINDOW_RESIZABLE, &window, &renderer)) {
		std::cout << "Couldn't create window/renderer: " << SDL_GetError() << std::endl;
		return 2;
	}
	img = IMG_LoadTexture(renderer, "./res/princess.png");
	if (!img) {
		std::cout << "Failed to load image: " << SDL_GetError() << std::endl;
		return 3;
	}

	SDL_Thread *theSecondary = SDL_CreateThread(render_thread, NULL, NULL);
	SDL_Event event;
	while (RUNNING) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_EVENT_QUIT) {
				RUNNING = false;
			}
			if (event.type == SDL_EVENT_KEY_UP) {
				x += 5;
				dst = {x, 100.0f, 300.0f, 300.0f};
			}
		}

		clock1.tick(60);
	}
	SDL_WaitThread(theSecondary, NULL);
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();

	return 0;
}