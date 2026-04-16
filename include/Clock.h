#ifndef CLOCK_H
#define CLOCK_H

#include <SDL3/SDL.h>


struct Clock
{
	Uint64 last;
	Clock();
	void tick(int fps);
};

#endif