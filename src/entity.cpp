#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include "Entity.h"



Entity::Entity()
: _img(NULL) {}

Entity::Entity(SDL_Texture *img, SDL_FRect dst)
: _img(img), _dst(dst) {}

void Entity::cleanUp()
{
	SDL_DestroyTexture(_img);
}

SDL_Texture* Entity::get_img()
{
	return _img;
}

SDL_FRect* Entity::get_dst()
{
	return &_dst;
}

void Entity::move(float delta_x, float delta_y)
{
	_dst.x += delta_x;
	_dst.y += delta_y;
}