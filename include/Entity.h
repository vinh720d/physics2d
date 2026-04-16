#ifndef ENTITY_H
#define ENTITY_H

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>


class Entity
{
public:
	Entity();
	Entity(SDL_Texture *img, SDL_FRect dst);
	void cleanUp();
	SDL_Texture* get_img();
	SDL_FRect* get_dst();
	void move(float delta_x, float delta_y);
private:
	SDL_Texture *_img;
	SDL_FRect _dst;
};

#endif