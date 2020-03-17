#include<stdio.h>
#include"SDL/SDL.h"
#include<SDL/SDL_image.h>
#include<SDL/SDL_mixer.h>
int main(void){
SDL_Surface *screen;
SDL_Surface *jouer,*image,*parametre,*quitter,*personnage,*pierre,*jouer1,*parametre1,*quitter1,*logo;
SDL_Rect postionimage,posjouer,posparametre,posquitter,postionjoueur,posob,poslogo;
SDL_Event event;
char pause;
int continuer=1,x=0,done=1;
Mix_Chunk *music,*music1;
Mix_AllocateChannels(2);
if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
{
printf("%s",Mix_GetError());
}
music=Mix_LoadWAV("hamza.wav");
music1=Mix_LoadWAV("deathnote.wav");
if(SDL_Init(SDL_INIT_VIDEO)!=0){
printf("unable to initialize SDL: %s\n",SDL_GetError());
return 1;
}
screen=SDL_SetVideoMode(720,544,0,SDL_HWSURFACE|SDL_DOUBLEBUF);
if(screen==NULL){
printf("unable to set video mode:%s\n",SDL_GetError());
return 1;
}
logo=IMG_Load("bible.png");
SDL_WM_SetCaption("BIBLE OF CENTAURUS !", NULL);
image=IMG_Load("ilyes.jpg");
jouer=IMG_Load("12.png");
jouer1=IMG_Load("11.png");
parametre1=IMG_Load("21.png");
parametre=IMG_Load("22.png");
quitter=IMG_Load("31.png");
quitter1=IMG_Load("32.png");
personnage=IMG_Load("detective.png");
postionimage.x=0;
postionimage.y=0;
postionjoueur.x=0;
postionjoueur.y=0;

postionimage.w=image->w;
postionimage.h=image->h;
image->w=1000;
image->h=667;
SDL_BlitSurface(image,NULL,screen,&postionimage);
posjouer.x=250;
posjouer.y=120;
posparametre.x=240;
posparametre.y=230;
posquitter.x=240;
posquitter.y=350;


poslogo.x=550;
poslogo.y=20;
Mix_PlayChannel(2,music1,-1);
SDL_BlitSurface(logo,NULL,screen,&poslogo);
SDL_BlitSurface(jouer1,NULL,screen,&posjouer);
SDL_BlitSurface(parametre1,NULL,screen,&posparametre);
SDL_BlitSurface(quitter,NULL,screen,&posquitter);
SDL_Flip(screen);

while(continuer)
{
done=1;
SDL_WaitEvent(&event);
switch(event.type)
{

case SDL_QUIT:
continuer=0;
break;
case SDL_KEYUP:
        switch(event.key.keysym.sym)
        {   
            case SDLK_UP:
                if(x==0)
               { x=2;
               break;}

               if(x==2)
              {  x=1;
               break;}
              if(x==1)
                {x=0;
                 break;}

            case SDLK_DOWN:
                x++;
                x=x%3;
                break;
            case SDLK_SPACE:
            if(x==0)
            continuer=0;
         if(x==2)
Mix_PlayChannel(1,music,0);
            if(x==1)
             {Mix_PlayChannel(1,music,0);
x=1;
while(done)
{
SDL_PollEvent(&event);
SDL_BlitSurface(image,NULL,screen,&postionimage);
SDL_BlitSurface(personnage,NULL,screen,&postionjoueur);
SDL_Flip(screen);
switch(event.type)
{
case SDL_KEYDOWN:
        switch(event.key.keysym.sym)
        {   case SDLK_ESCAPE:
             done=0;
             break;
            case SDLK_UP:
                postionjoueur.y--;
                break;
            case SDLK_DOWN:
                postionjoueur.y++;
                break;
            case SDLK_RIGHT:
                postionjoueur.x++;
                break;
            case SDLK_LEFT:
                postionjoueur.x--;
                break;
        }
        break;
}
}
while(done)
{
SDL_PollEvent(&event);
SDL_BlitSurface(image,NULL,screen,&postionimage);
SDL_BlitSurface(personnage,NULL,screen,&postionjoueur);
SDL_Flip(screen);
switch(event.type)
{
case SDL_KEYDOWN:
        switch(event.key.keysym.sym)
        {   case SDLK_ESCAPE:
             done=0;
             break;
            case SDLK_UP:
                postionjoueur.y--;
                break;
            case SDLK_DOWN:
                postionjoueur.y++;
                break;
            case SDLK_RIGHT:
                postionjoueur.x++;
                break;
            case SDLK_LEFT:
                postionjoueur.x--;
                break;
        }
        break;
}
}}
           break;

done=1;
}  
if(x==1)
{
SDL_BlitSurface(image,NULL,screen,&postionimage);
SDL_BlitSurface(jouer,NULL,screen,&posjouer);
SDL_BlitSurface(logo,NULL,screen,&poslogo);
SDL_BlitSurface(parametre1,NULL,screen,&posparametre);
SDL_BlitSurface(quitter,NULL,screen,&posquitter);
SDL_Flip(screen);}
if(x==2)
{
SDL_BlitSurface(image,NULL,screen,&postionimage);
SDL_BlitSurface(jouer1,NULL,screen,&posjouer);
SDL_BlitSurface(logo,NULL,screen,&poslogo);
SDL_BlitSurface(parametre,NULL,screen,&posparametre);
SDL_BlitSurface(quitter,NULL,screen,&posquitter);
SDL_Flip(screen);}
if(x==0)
{
SDL_BlitSurface(image,NULL,screen,&postionimage);
SDL_BlitSurface(jouer1,NULL,screen,&posjouer);
SDL_BlitSurface(logo,NULL,screen,&poslogo);
SDL_BlitSurface(parametre1,NULL,screen,&posparametre);
SDL_BlitSurface(quitter1,NULL,screen,&posquitter);
SDL_Flip(screen);}
break;
case SDL_MOUSEMOTION:
if((event.motion.x<500&&event.motion.x>250)&&(event.motion.y<187&&event.motion.y>120))
{
SDL_BlitSurface(image,NULL,screen,&postionimage);
SDL_BlitSurface(jouer,NULL,screen,&posjouer);
SDL_BlitSurface(logo,NULL,screen,&poslogo);
SDL_BlitSurface(parametre1,NULL,screen,&posparametre);
SDL_BlitSurface(quitter,NULL,screen,&posquitter);
SDL_Flip(screen);
}
if(!(((event.motion.x<500&&event.motion.x>250)&&(event.motion.y<187&&event.motion.y>120))||(event.motion.x<500&&event.motion.x>250)&&(event.motion.y<277&&event.motion.y>230)||(event.motion.x<500&&event.motion.x>250)&&(event.motion.y<397&&event.motion.y>350)))
{
SDL_BlitSurface(image,NULL,screen,&postionimage);
SDL_BlitSurface(jouer1,NULL,screen,&posjouer);
SDL_BlitSurface(logo,NULL,screen,&poslogo);
SDL_BlitSurface(parametre1,NULL,screen,&posparametre);
SDL_BlitSurface(quitter,NULL,screen,&posquitter);
SDL_Flip(screen);

}
if((event.motion.x<500&&event.motion.x>250)&&(event.motion.y<277&&event.motion.y>230))
{
SDL_BlitSurface(image,NULL,screen,&postionimage);
SDL_BlitSurface(jouer1,NULL,screen,&posjouer);
SDL_BlitSurface(logo,NULL,screen,&poslogo);
SDL_BlitSurface(parametre,NULL,screen,&posparametre);
SDL_BlitSurface(quitter,NULL,screen,&posquitter);
SDL_Flip(screen);
}
if((event.motion.x<500&&event.motion.x>250)&&(event.motion.y<397&&event.motion.y>350))
{
SDL_BlitSurface(image,NULL,screen,&postionimage);
SDL_BlitSurface(jouer1,NULL,screen,&posjouer);
SDL_BlitSurface(logo,NULL,screen,&poslogo);
SDL_BlitSurface(parametre1,NULL,screen,&posparametre);
SDL_BlitSurface(quitter1,NULL,screen,&posquitter);
SDL_Flip(screen);
}
break;
case SDL_MOUSEBUTTONDOWN :
if((event.button.button==SDL_BUTTON_LEFT)&&(event.button.x<668&&event.button.x>250)&&(event.button.y<187&&event.button.y>120))
{
Mix_PlayChannel(1,music,0);
while(done)
{
SDL_PollEvent(&event);
SDL_BlitSurface(image,NULL,screen,&postionimage);
SDL_BlitSurface(personnage,NULL,screen,&postionjoueur);
SDL_Flip(screen);
switch(event.type)
{
case SDL_KEYDOWN:
        switch(event.key.keysym.sym)
        {   case SDLK_ESCAPE:
             done=0;
             break;
            case SDLK_UP:
                postionjoueur.y--;
                break;
            case SDLK_DOWN:
                postionjoueur.y++;
                break;
            case SDLK_RIGHT:
                postionjoueur.x++;
                break;
            case SDLK_LEFT:
                postionjoueur.x--;
                break;
        }
        break;
}
}
}
if((event.button.button==SDL_BUTTON_LEFT)&&(event.button.x<500&&event.button.x>250)&&(event.button.y<277&&event.button.y>230))
{
Mix_PlayChannel(1,music,0);

SDL_Flip(screen);
}
if((event.button.button==SDL_BUTTON_LEFT)&&(event.button.x<500&&event.button.x>250)&&(event.button.y<397&&event.button.y>350))
{
Mix_PlayChannel(1,music,0);
continuer=0;
SDL_Flip(screen);
}}
}
return 1;
}	
