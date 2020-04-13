#ifndef SCORE_H_INCLUDED
#define SCORE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>





typedef struct 
{
SDL_Rect box1;
SDL_Rect box2;
}box;
int Collision(SDL_Rect* box1,SDL_Rect* box2);


#endif
