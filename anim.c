
#include <SDL/SDL.h>
#include "anim.h"



int gameover;


SDL_Rect rcSrc, rcSprite;

void HandleEvent(SDL_Event event)
{
	switch (event.type) {
		
		case SDL_QUIT:
			gameover = 1;
			break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym) {
				case SDLK_ESCAPE:
				gameover = 1;
                                case SDLK_q:
					gameover = 1;
					break;
				case SDLK_LEFT:
					if ( rcSrc.x == 192)
						rcSrc.x = 128;
					else if(rcSrc.x == 128)
						rcSrc.x = 68;

					else if(rcSrc.x == 68)
                                               rcSrc.x = 0;
                                        else
                                               rcSrc.x = 128;
                                        rcSprite.x -= 10;
                                         
					break;
				case SDLK_RIGHT:
					if ( rcSrc.x == 256 )
						rcSrc.x = 320;
					else if(rcSrc.x == 320)
						rcSrc.x = 380;
					else if(rcSrc.x == 380)
                                               rcSrc.x = 448;
                                        else
                                               rcSrc.x = 320;
                                        rcSprite.x += 10;
					break;
			}
			break;
	}
}

int main(int argc, char* argv[])
{
	SDL_Surface *screen, *temp, *sprite, *grass;
	SDL_Rect rcGrass;
	int colorkey;

	
	SDL_Init(SDL_INIT_VIDEO);

	
	SDL_WM_SetCaption("SDL Animation", "SDL Animation");

	
	screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0);

	
	SDL_EnableKeyRepeat(70, 70);

	
	temp   = SDL_LoadBMP("ss2.bmp");
	sprite = SDL_DisplayFormat(temp);//convertir une surface en un autre avec le même format que l'écran
	SDL_FreeSurface(temp);

	
	colorkey = SDL_MapRGB(screen->format, 255, 0, 255);
	SDL_SetColorKey(sprite, SDL_SRCCOLORKEY | SDL_RLEACCEL, colorkey);

	
	temp  = IMG_Load("jungle.png");
	grass = SDL_DisplayFormat(temp);
	SDL_FreeSurface(temp);

	
	rcSprite.x = 300;
	rcSprite.y = 100;

	
	rcSrc.x = 256;
	rcSrc.y = 0;
	rcSrc.w = SPRITE_SIZE;
	rcSrc.h = SPRITE_SIZE;

	gameover = 0;

	
	while (!gameover)
	{
		SDL_Event event;
		SDL_WaitEvent(&event);
			HandleEvent(event);
		SDL_BlitSurface(grass, NULL, screen, &rcGrass);
		SDL_BlitSurface(sprite, &rcSrc, screen, &rcSprite);
		SDL_UpdateRect(screen, 0, 0, 0, 0);
	}

	
	SDL_FreeSurface(sprite);
	SDL_FreeSurface(grass);
	SDL_Quit();

	return 0;
}
