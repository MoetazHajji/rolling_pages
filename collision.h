#include "option.h"
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h> 
#include <SDL/SDL_ttf.h>


int collision(SDL_Rect hero,SDL_Rect autre);
SDL_Color GetPixel(SDL_Surface *surface,int x,int y);
