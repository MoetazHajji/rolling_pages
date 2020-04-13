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
          return 1;
}


int main(int argc, char *argv[])
{

        SDL_Init(SDL_INIT_EVERYTHING);
        SDL_Surface *ecran;
        int running = 1;
        const int FPS = 30;
        ecran = SDL_SetVideoMode(640,480, 32, SDL_SWSURFACE);

 SDL_Rect box1;
        box1.x = 10;
        box1.y = 10;
        box1.w = 20;
        box1.h = 20;

 SDL_Rect box2;
        box2.x = 100;
        box2.y = 100;
        box2.w = 200;
        box2.h = 300;

Uint32 color2 = SDL_MapRGB(ecran->format, 0xff,0xff,0xff);
        Uint32 color = SDL_MapRGB(ecran->format, 0,0,0);

SDL_FillRect(ecran,&box2,color2);
 SDL_EnableKeyRepeat(10,10);

  while(running) {


                SDL_Event event;
                while(SDL_PollEvent(&event)) {
                        switch(event.type) {
                                case SDL_QUIT:
                                        running = 0;
                                        break;
                                case SDL_KEYDOWN:
                                        switch(event.key.keysym.sym) {

                                                                      case SDLK_UP:
SDL_FillRect(ecran, &box1, color);
                                                                          box1.y--;
                                                                           if(Collision(&box1,&box2))
                                                                              box1.y++;
                                                                      break;

                                                                      case SDLK_LEFT:
SDL_FillRect(ecran, &box1, color);
                                                                               box1.x--;
                                                                            if(Collision(&box1,&box2))
                                                                               box1.x++;
                                                                       break;

                                                                    case SDLK_DOWN:
SDL_FillRect(ecran, &box1, color);
                                                                                 box1.y++;
                                                                               if(Collision(&box1,&box2))
                                                                               box1.y--;
                                                                    break;

                                                                    case SDLK_RIGHT:
SDL_FillRect(ecran, &box1, color);
                                                                                box1.x++;
                                                                               if(Collision(&box1,&box2))
                                                                               box1.x--;
                                                                    break;

                                                                     } break;

                                      }
                                 }

      SDL_FillRect(ecran, &box1, color2);
                SDL_Flip(ecran);



  }
  SDL_Quit();
    return EXIT_SUCCESS;
}
