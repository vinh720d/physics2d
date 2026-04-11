#include <SDL3/SDL.h>
#include "Clock.hpp"




Clock::Clock() : last(SDL_GetTicks()) {}

void Clock::tick(int fps)
{
	float frametime = 1000.0 / fps;
	Uint64 elapsed = SDL_GetTicks() - last;
	if (elapsed < frametime)
	{
		SDL_Delay((Uint32)(frametime - elapsed));
	}
	last = SDL_GetTicks();
}