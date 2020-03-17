#include<stdio.h>
#include"SDL/SDL.h"
#include<SDL/SDL_image.h>
#include<SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
int main(void){
SDL_Surface *screen;
//

//
SDL_Surface *jouer,*image,*parametre,*quitter,*personnage,*pierre,*jouer1,*parametre1,*quitter1,*logo,*photo,*love,*love1,*love2,*love3,*la,*texte,*fond;
SDL_Rect postionimage,posjouer,posparametre,posquitter,postionjoueur,posob,poslogo,postionphoto,poslove,poslove1,poslove2,poslove3,postionla,position;
SDL_Event event;
SDL_Color couleurNoire = {0, 0, 0};
TTF_Font *police;

love=IMG_Load("love.png");
love1=IMG_Load("love1.png");
love2=IMG_Load("love2.png");
love3=IMG_Load("love3.png");
la=IMG_Load("ilyesss.jpg");
char pause;
int continuer=1,x=0,done=1;
Mix_Chunk *music,*music1,*music2;
Mix_AllocateChannels(3);
if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
{
printf("%s",Mix_GetError());
}
music=Mix_LoadWAV("hamza.wav");
music1=Mix_LoadWAV("deathnote.wav");
music2=Mix_LoadWAV("deathnote2.wav");
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
SDL_WM_SetCaption("ROOLING PAGES", NULL);
photo=IMG_Load("photo.jpg");
image=IMG_Load("ilyes.jpg");
jouer=IMG_Load("12.png");
jouer1=IMG_Load("11.png");
parametre1=IMG_Load("21.png");
parametre=IMG_Load("22.png");
quitter=IMG_Load("31.png");
quitter1=IMG_Load("32.png");
personnage=IMG_Load("per.png");
SDL_SetColorKey(personnage, SDL_SRCCOLORKEY, SDL_MapRGB(personnage->format, 255, 255, 255));
postionimage.x=0;
postionimage.y=0;
postionjoueur.x=0;
postionjoueur.y=0;
postionphoto.x=0;
postionphoto.y=0;
postionla.x=0;
postionla.y=0;
postionimage.w=image->w;
postionimage.h=image->h;
postionphoto.w=photo->w;
postionphoto.h=photo->h;
postionla.w=photo->w;
postionla.h=photo->h;
poslove.x=0;
poslove.y=200;
poslove1.x=0;
poslove1.y=200;
poslove2.x=0;
poslove2.y=200;
poslove3.x=0;
poslove3.y=200;

image->w=1000;
image->h=667;

SDL_BlitSurface(la,NULL,screen,&postionla);
SDL_Flip(screen);
SDL_Delay(500);
SDL_BlitSurface(love,NULL,screen,&poslove);
SDL_Flip(screen);
SDL_Delay(500);
SDL_BlitSurface(love1,NULL,screen,&poslove1);
SDL_Flip(screen);
SDL_Delay(500);
SDL_BlitSurface(love2,NULL,screen,&poslove2);
SDL_Flip(screen);
SDL_Delay(500);
SDL_BlitSurface(love3,NULL,screen,&poslove3);
SDL_Flip(screen);
SDL_Delay(500);



SDL_BlitSurface(image,NULL,screen,&postionimage);
posjouer.x=250;
posjouer.y=120;
posparametre.x=240;
posparametre.y=230;
posquitter.x=240;
posquitter.y=340;


poslogo.x=10;
poslogo.y=10;
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
}  
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
//
case SDL_MOUSEBUTTONDOWN :
if((event.button.button==SDL_BUTTON_LEFT)&&(event.button.x<668&&event.button.x>250)&&(event.button.y<187&&event.button.y>120))
{
Mix_PlayChannel(1,music,0);

while(done)
{
SDL_PollEvent(&event);
SDL_BlitSurface(photo,NULL,screen,&postionphoto);
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
SDL_PauseAudio(0);

}
if((event.button.button==SDL_BUTTON_LEFT)&&(event.button.x<500&&event.button.x>250)&&(event.button.y<277&&event.button.y>230))
{
Mix_PlayChannel(1,music,0);
SDL_Delay(200);

while(done)
{
SDL_PollEvent(&event);
SDL_BlitSurface(photo,NULL,screen,&postionphoto);
SDL_Flip(screen);
 SDL_PauseAudio(2);
switch(event.type)
{
case SDL_KEYDOWN:
        switch(event.key.keysym.sym)
        {   case SDLK_ESCAPE:
             done=0;
             break;
            
        }

      break;
 TTF_Init();
police = TTF_OpenFont("ALBA.TTF", 65);
    texte = TTF_RenderText_Blended(police, "ROOLING PAGES", couleurNoire);

SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));

        position.x = 0;
        position.y = 0;
        position.x = 60;
        position.y = 370;
        SDL_BlitSurface(texte, NULL, screen, &position); 
        SDL_Flip(screen);

}
}
SDL_PauseAudio(0);
TTF_CloseFont(police);
    TTF_Quit();
 SDL_FreeSurface(texte);
}
//////
if((event.button.button==SDL_BUTTON_LEFT)&&(event.button.x<48&&event.button.x>10)&&(event.button.y<41&&event.button.y>10))
{

Mix_PlayChannel(1,music,0);
SDL_Delay(200);

while(done)
{
SDL_PollEvent(&event);
SDL_BlitSurface(image,NULL,screen,&postionimage);
SDL_BlitSurface(jouer1,NULL,screen,&posjouer);
SDL_BlitSurface(logo,NULL,screen,&poslogo);
SDL_BlitSurface(parametre1,NULL,screen,&posparametre);
SDL_BlitSurface(quitter,NULL,screen,&posquitter);
SDL_Flip(screen);
 SDL_PauseAudio(2);
if((event.button.button==SDL_BUTTON_LEFT)&&(event.button.x<58&&event.button.x>20)&&(event.button.y<51&&event.button.y>10))
{
SDL_PauseAudio(0);
}
switch(event.type)
{
case SDL_KEYDOWN:
        switch(event.key.keysym.sym)
        {   case SDLK_ESCAPE:
             done=0;
             break;
            
        }

      break;
}


}
SDL_PauseAudio(0);
}
/////
if((event.button.button==SDL_BUTTON_LEFT)&&(event.button.x<500&&event.button.x>250)&&(event.button.y<397&&event.button.y>350))
{
Mix_PlayChannel(1,music,0);
continuer=0;
SDL_Flip(screen);
}}
}
return 1;
}	

