#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <stdexcept>

#include "RenderWindow.hpp"
#include "Clock.hpp"


const int WIDTH = 700, HEIGHT = 500;
SDL_Texture *img = nullptr;
SDL_FRect dst = {100.0f, 100.0f, 128.0f, 128.0f};


Clock clock;



int main(int argc, const char *argv[])
{
	if (!SDL_Init(SDL_INIT_VIDEO)) {
		SDL_Log("Couldn't init SDL: %s\n", SDL_GetError());
	}

	try {
		RenderWindow window("First SDL app!", WIDTH, HEIGHT, SDL_WINDOW_RESIZABLE);


		img = window.loadTexture("./res/the_girl.png");

		SDL_Event event;
		bool RUNNING = true;
		while (RUNNING) {
			while (SDL_PollEvent(&event)) {
				if (event.type == SDL_EVENT_QUIT) {
					RUNNING = false;
				}
				if (event.type == SDL_EVENT_KEY_DOWN) {
					dst.x += 5;
				}
			}

			window.clearRenderer();

			window.setRendererColorFloat(1.0f, 1.0f, 1.0f, 1.0f);

			window.render(img, NULL, &dst);

			window.renderScreen();

			clock.tick(60);
		}
	} catch (const std::runtime_error &e) {
		SDL_Log("Couldn't create window/renderer: %s\n", e.what());
		return 1;
	}
	SDL_DestroyTexture(img);

	return 0;
}