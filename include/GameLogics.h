#ifndef GAMELOGICS_H
#define GAMELOGICS_H

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

#include "Game.h"

class GameLogics
{
public:
	GameLogics();
	~GameLogics();
	void draw_circle(SDL_Renderer *renderer, float x, float y, float radius);
	void update(Game *gg);
	void render(SDL_Renderer *renderer);
private:
	SDL_Texture *canvas;
	SDL_Texture *popup;
	int scr_w, scr_h;
	float x, y;
	float radius = 10.0f;
	bool painting = false;
};

#endif