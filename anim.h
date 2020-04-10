#ifndef ANIM_H
#define ANIM_H

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>



#define SCREEN_WIDTH  720	
#define SCREEN_HEIGHT 544
#define SPRITE_SIZE    64

void HandleEvent(SDL_Event event);
int main(int argc, char* argv[]);
#endif
