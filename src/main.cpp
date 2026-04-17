#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

#include "Game.h"
#include "Clock.h"

const int WIDTH = 700, HEIGHT = 500;
Game gg;
Clock g_clock;

int main(int argc, const char *argv[])
{
	gg.init("This is my first SDL program!", WIDTH, HEIGHT, SDL_WINDOW_RESIZABLE);

	while (gg.running) {
		gg.handle_event();
		gg.update();
		gg.render();
		g_clock.tick(60);
	}
	return 0;
}