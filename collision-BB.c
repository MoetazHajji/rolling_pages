/**

* un rectangle aligné avec les axes, ses cotés sont parallèles aux axes des x et des y repère

*/
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include "boundingbox.h"

int Collision(SDL_Rect* box1,SDL_Rect* box2)
{
   if((box2->x >= box1->x + box1->w)|| (box2->x + box2->w <= box1->x) || (box2->y >= box1->y + box1->h) || (box2->y + box2->h <= box1->y))
          return 0;
   else
printf("changement couleur");
          return 1;
}



