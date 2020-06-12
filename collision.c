#include "collision.h"

int collision(SDL_Rect hero,SDL_Rect autre)//bounding box
{
   if((autre.x <= hero.x + hero.w)&& (autre.x + autre.w >= hero.x)&& (autre.y <= hero.y + hero.h)&& (autre.y +autre.h>= hero.y))
          return 1; 
   else
          return 0; 
}
int Collision(int x,int y,SDL_Rect C)
{
   int d2 = (x-C.x)*(x-C.x) + (y-C.y)*(y-C.y);
   if (d2>C.w/2*C.w/2)
      return 0;
   else
      return 1;
}
