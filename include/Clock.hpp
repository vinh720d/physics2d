#pragma once

#include <SDL3/SDL.h>


struct Clock
{
	Uint64 last;
	Clock();
	void tick(int fps);
};