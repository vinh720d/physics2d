#include "SDL3/SDL_render.h"
#define SDL_MAIN_USE_CALLBACKS
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>




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

extern "C"
{
	SDL_AppResult SDL_AppInit(void **appstate, int argc, char *argv[])
	{
		if (!SDL_Init(SDL_INIT_VIDEO))
		{
			SDL_Log("Couldn't initialize SDL: %s", SDL_GetError());
			return SDL_APP_FAILURE;
		}

		if (!SDL_CreateWindowAndRenderer("First SDL program!", 500, 500, SDL_WINDOW_RESIZABLE, &window, &renderer))
		{
			SDL_Log("Couldn't create window/renderer: %s", SDL_GetError());
			return SDL_APP_FAILURE;
		}

		SDL_SetRenderLogicalPresentation(renderer, 300, 300, SDL_LOGICAL_PRESENTATION_LETTERBOX);

		return SDL_APP_CONTINUE;
	}

	SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event)
	{
		if (event->type == SDL_EVENT_QUIT)
		{
			return SDL_APP_SUCCESS;
		}
		return SDL_APP_CONTINUE;
	}

	SDL_AppResult SDL_AppIterate(void *appstate)
	{
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

		SDL_RenderClear(renderer);

		SDL_RenderPresent(renderer);

		clock.tick(30);
		return SDL_APP_CONTINUE;
	}

	void SDL_AppQuit(void *appstate, SDL_AppResult result)
	{
		SDL_DestroyWindow(window);
		SDL_DestroyRenderer(renderer);
		SDL_Quit();
	}
}