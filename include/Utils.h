#ifndef UTILS_H
#define UTILS_H

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>



class Utils
{
public:
	Utils();
	Utils(SDL_Renderer *renderer);
	SDL_Texture* loadTexture(const char *file);
private:
	SDL_Renderer *_renderer;
};



#endif