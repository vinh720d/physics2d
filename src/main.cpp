#include <SDL3/SDL.h>
#include <iostream>



static SDL_Window *window = NULL;
static SDL_Renderer *renderer = NULL;

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
} clock;


int main(int argc, const char *argv[])
{
	if (!SDL_Init(SDL_INIT_VIDEO)) {
		std::cout << "Couldn't init SDL: " << SDL_GetError() << std::endl;
		return 1;
	}

	if (!SDL_CreateWindowAndRenderer("First SDL app!", 1000, 618, SDL_WINDOW_RESIZABLE, &window, &renderer)) {
		std::cout << "Couldn't create window/renderer: " << SDL_GetError() << std::endl;
		return 2;
	}

	bool RUNNING = true;
	SDL_Event event;
	while (RUNNING) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_EVENT_QUIT) {
				RUNNING = false;
			}
		}

		SDL_RenderClear(renderer);

		const double now = ((double)SDL_GetTicks()) / 1000.0;
		const float red = (float) (0.5 + 0.5 * SDL_sin(now));
		const float green = (float) (0.5 + 0.5 * SDL_sin(now + SDL_PI_D * 2 / 3));
		const float blue = (float) (0.5 + 0.5 * SDL_sin(now + SDL_PI_D * 4 / 3));

		SDL_SetRenderDrawColorFloat(renderer, red, green, blue, SDL_ALPHA_OPAQUE_FLOAT);

		SDL_RenderPresent(renderer);

		clock.tick(60);
	}
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();

	return 0;
}