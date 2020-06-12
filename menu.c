#include "menu.h"
//menu(load element)
void chargerTous(SDL_Surface **ecran,SDL_Surface **star,SDL_Surface **shab1,SDL_Surface **shab2,SDL_Surface **shab3,SDL_Surface **menu,SDL_Surface **texteplay,SDL_Surface **textemulti,SDL_Surface **texteoption,SDL_Surface **textequit,Mix_Music **musique,Mix_Chunk **effet,Mix_Chunk **sonspell,Mix_Chunk **dying,Mix_Chunk **hit, Mix_Chunk **effet2,TTF_Font **police,TTF_Font **police1,SDL_Color couleur)
{
    
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
    
    SDL_WM_SetIcon(IMG_Load("image/icon.png"), NULL);
    (*ecran) = SDL_SetVideoMode(1366, 768, 32, SDL_HWSURFACE | SDL_DOUBLEBUF |SDL_RESIZABLE); //|SDL_FULLSCREEN);
    SDL_WM_SetCaption("rolling pages", NULL);
	(*star)=IMG_Load("image/star.png");
	(*shab1)=IMG_Load("image/shab1.png");
	(*shab2)=IMG_Load("image/shab2.png");
	(*shab3)=IMG_Load("image/shab3.png");
    	(*menu) = IMG_Load("image/menu.png");
   

    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);
    (*effet) = Mix_LoadWAV("music/boutonn.wav");
    (*effet2) = Mix_LoadWAV("music/boutofff.wav");
    (*sonspell)= Mix_LoadWAV("music/sonspell.wav");
    //(*hit)=Mix_LoadWAV("music/
    (*dying)=Mix_LoadWAV("music/hero dying2.wav");
    (*musique) = Mix_LoadMUS("music/menu.mp3");

    (*police) = TTF_OpenFont("fonts/Takota.ttf", 70);
    (*police1)= TTF_OpenFont("fonts/calibri.ttf", 20);
    (*texteplay) = TTF_RenderText_Blended((*police), "1: NEW GAME", couleur);
    (*textemulti) = TTF_RenderText_Blended((*police), "2: CONTINUE", couleur);
    (*texteoption) = TTF_RenderText_Blended((*police), "3: OPTION", couleur);
    (*textequit) = TTF_RenderText_Blended((*police), "0: QUIT", couleur);
}
//menu
void remplirlesposition(SDL_Rect *positionFond,SDL_Rect *posquit,SDL_Rect *posmulti,SDL_Rect *posoption, SDL_Rect *posplay,SDL_Rect *posstar,SDL_Rect *poscquit,SDL_Rect *poscmulti,SDL_Rect *poscoption,SDL_Rect *poscplay,SDL_Rect *posshab1,SDL_Rect *posshab2,SDL_Rect *posshab3,SDL_Rect *posvolb)
{
    posvolb->x=660;
    posvolb->y=363;
    posshab1->x=10;
    posshab1->y=40;
    posshab2->x=500;
    posshab2->y=200;
    posshab3->x=1170;
    posshab3->y=190;
    posstar->x=655;
    posstar->y=130;
    positionFond->x = 0;
    positionFond->y =0;
    posplay->x=120;
    posplay->y=200;
    posquit->x=120;
    posquit->y=560;
    posmulti->x=120;
    posmulti->y=320;
    posoption->x=120;
    posoption->y=440;
    poscplay->x=400;
    poscplay->y=200;
    poscquit->x=260;
    poscquit->y=560;
    poscmulti->x=400;
    poscmulti->y=320;
    poscoption->x=310;
    poscoption->y=440;

}


void transparent(int *a,int*b)
{
(*a)+=(*b);
			if (((*a)==254)||((*a)==0))
				(*b)=-(*b);

}
//son lors de click sur les buttons du menu(changrmrnt couleur et son)
void affichagetextmenu(TTF_Font **police,TTF_Font **police1,SDL_Color couleur,SDL_Color couleur2,SDL_Event event,SDL_Surface **texteplay,SDL_Surface **textemulti,SDL_Surface **texteoption,SDL_Surface  **textequit,SDL_Surface **commentaireplay,SDL_Surface  **commentaireoption,SDL_Surface **commentairemulti,SDL_Surface **commentairequit,Mix_Chunk *effet,int *son,int *mute)
{
FILE * fichier =NULL;


if (event.motion.x<480  && event.motion.x>120 && event.motion.y<290 && event.motion.y>200)
                {
                    TTF_SetFontStyle((*police), TTF_STYLE_UNDERLINE);
                    (*texteplay)= TTF_RenderText_Blended((*police), "1: NEW GAME", couleur2);
                    TTF_SetFontStyle((*police1), TTF_STYLE_UNDERLINE);
                    (*commentaireplay) = TTF_RenderText_Blended((*police1), "play new game", couleur);
                    if ((*son)==0 && *mute==0)
                    {
                        (*son)=1;
                        Mix_PlayChannel( -1, effet, 0 ) ;
                    }
                }
                else if (event.motion.x<450  && event.motion.x>120 && event.motion.y<400 && event.motion.y>340)
                {
                   TTF_SetFontStyle((*police), TTF_STYLE_UNDERLINE);
                    (*textemulti)= TTF_RenderText_Blended((*police), "2: CONTINUE", couleur2);
                     TTF_SetFontStyle((*police1), TTF_STYLE_UNDERLINE);
                    (*commentairemulti)= TTF_RenderText_Blended((*police1), "continue game", couleur);
                    if ((*son)==0 && *mute==0)
                    {
                        (*son)=1;
                        Mix_PlayChannel( -1, effet, 0 ) ;
                    }
                }
                else if (event.motion.x<385  && event.motion.x>120 && event.motion.y<520 && event.motion.y>450)
                {
                    TTF_SetFontStyle((*police), TTF_STYLE_UNDERLINE);
                    (*texteoption) = TTF_RenderText_Blended((*police), "3: OPTION", couleur2);
                    TTF_SetFontStyle((*police1), TTF_STYLE_UNDERLINE);
                    (*commentaireoption)= TTF_RenderText_Blended((*police1), "go to menu option", couleur);
                    if ((*son)==0 && *mute==0)
                    {
                        (*son)=1;
                        Mix_PlayChannel( -1, effet, 0 ) ;
                    }
                }
                else if (event.motion.x<320  && event.motion.x>120 && event.motion.y<640 && event.motion.y>560)
                {
                    TTF_SetFontStyle((*police), TTF_STYLE_UNDERLINE);
                    (*textequit) = TTF_RenderText_Blended((*police), "0: QUIT", couleur2);
                    TTF_SetFontStyle((*police1), TTF_STYLE_UNDERLINE);
	  	    (*commentairequit)= TTF_RenderText_Blended((*police1), "leave game", couleur);
                    if ((*son)==0 && *mute==0)
                    {
                        (*son)=1;
                        Mix_PlayChannel( -1, effet, 0 ) ;
                    }
                }
                else
                {
                    (*son)=0;
                 TTF_SetFontStyle((*police), TTF_STYLE_NORMAL);
                    (*texteplay)= TTF_RenderText_Blended((*police), "1: NEW GAME", couleur);
                   (*textemulti)= TTF_RenderText_Blended((*police), "2: CONTINUE", couleur);
                    (*texteoption)= TTF_RenderText_Blended((*police), "3: OPTION", couleur);
                    (*textequit)= TTF_RenderText_Blended((*police), "0: QUIT", couleur);
                   (*commentaireplay)= NULL;
		   (*commentaireoption)= NULL ;
		   (*commentairequit)= NULL;
		   (*commentairemulti) =NULL;
		}
}
//choisit des boutton du menu
void buttons(SDL_Surface *ecran,SDL_Event event,Mix_Chunk *effet,Mix_Chunk *effet2,int *continuer,Mix_Music *musique,int *mute,SDL_Rect *posvolb,Mix_Music *intro,Mix_Chunk *sonspell,Mix_Chunk *dying,Mix_Chunk *hit, int *victory)
{
int boucle;
FILE* fichier = NULL;
	int e=0;
if (event.button.button == SDL_BUTTON_LEFT && event.motion.x<500 && event.motion.x>120 && event.motion.y<290 && event.motion.y>200)
		{
			bouton_newgame (ecran, event,effet,effet2,continuer,musique,mute,posvolb,intro,sonspell,dying,hit,victory);
		}
if (event.button.button == SDL_BUTTON_LEFT && event.motion.x<450  && event.motion.x>120 && event.motion.y<400 && event.motion.y>340)
{
				fichier = fopen("Xstage", "r");
    				if (fichier != NULL)
    				{
    					fscanf(fichier,"%d",&e);
    					if (e==1)
    					{
    						stage1s(ecran,continuer,intro,effet,effet2,musique,mute,posvolb,sonspell,dying,hit,victory);
    						if ((*victory)==1)
               					{
               						stage2(ecran,continuer,intro,effet,effet2,musique,mute,posvolb,sonspell,dying,hit,victory);
               					}
               				
    					}
    					else if (e==2)
    					{
    						stage2s(ecran,continuer,intro,effet,effet2,musique,mute,posvolb,sonspell,dying,hit,victory);
    				
    				}	            		
}
if (event.button.button == SDL_BUTTON_LEFT && event.motion.x<385  && event.motion.x>120 && event.motion.y<520 && event.motion.y>450)
                {
                        if ((*mute)==0)
           		{
           			Mix_PlayChannel( -1, effet2, 0 ) ;
           		}
                    option(ecran,effet,effet2,musique,mute,continuer,posvolb);
                }
                else if (event.button.button == SDL_BUTTON_LEFT && event.motion.x<320  && event.motion.x>120 && event.motion.y<640 && event.motion.y>560)
                {
                        if ((*mute)==0)
           		{
           		Mix_PlayChannel( -1, effet2, 0 ) ;
           		}
                    (*continuer) = 0;
                }
}
void buttons1(SDL_Surface *ecran,SDL_Event event,Mix_Chunk *effet,Mix_Chunk *effet2,int *continuer,Mix_Music *musique,int *mute,SDL_Rect *posvolb,Mix_Music *intro,Mix_Chunk *sonspell,Mix_Chunk *dying,Mix_Chunk *hit, int *victory)
{
		int e=0;
		FILE* fichier = NULL;
                switch (event.key.keysym.sym)
                {
			case SDLK_KP1:
			bouton_newgame (ecran, event,effet,effet2,continuer,musique,mute,posvolb,intro,sonspell,dying,hit,victory);
			break;
			case SDLK_KP2:
				fichier = fopen("Xstage", "r");
    				if (fichier != NULL)
    				{
    					fscanf(fichier,"%d",&e);
    					if (e==1)
    					{
    						stage1s(ecran,continuer,intro,effet,effet2,musique,mute,posvolb,sonspell,dying,hit,victory);
    						if ((*victory)==1)
               					{
               						stage2(ecran,continuer,intro,effet,effet2,musique,mute,posvolb,sonspell,dying,hit,victory);
               					}
               				
    					}
    					else if (e==2)
    					{
    						stage2s(ecran,continuer,intro,effet,effet2,musique,mute,posvolb,sonspell,dying,hit,victory);
    				
    				}
			break;
			case SDLK_KP3:
			option(ecran,effet,effet2,musique,mute,continuer,posvolb);
			break;
			case SDLK_KP4:
			(*continuer)=0;
			break;
                }
               
}
void positionenemie(int *i,int *k)
{       if((*k)==2)
                (*i)--;
	if((*k)==1)
		(*i)++;
	if((*i)==20)
	(*k)=2;
	if((*i)==0)
	(*k)=1;	
}
//*
void positionshab(SDL_Rect *posshab1,SDL_Rect *posshab2,SDL_Rect *posshab3, int *direction,int *direction2,int *direction3)
{
    posshab1->x=posshab1->x+(*direction);
    if(posshab1->x==200 || posshab1->x==10)
        (*direction)=-(*direction);
    posshab2->x=posshab2->x+(*direction2);
    if(posshab2->x==500 || posshab2->x==700)
        (*direction2)=-(*direction2);
    posshab3->x=posshab3->x+(*direction3);
    if(posshab3->x==1170 || posshab3->x==1250)
        (*direction3)=-(*direction3);
}
//menu du jeu lors de click sur newgame (choix des button mono/multi/back)
void bouton_newgame (SDL_Surface *ecran,SDL_Event event,Mix_Chunk *effet,Mix_Chunk *effet2,int *continuer,Mix_Music *musique,int *mute,SDL_Rect *posvolb,Mix_Music *intro,Mix_Chunk *sonspell,Mix_Chunk *dying,Mix_Chunk *hit, int *victory)
{
	SDL_Surface *backgr=NULL, *newg=NULL, *multi=NULL,*picnew=NULL,*picmulti=NULL,*back=NULL;
	SDL_Rect posbackgr, posnewg, posmulti,pospicnew,pospicmulti,posback;
	TTF_Font *police = NULL;
	backgr=IMG_Load ("image/soumenu.png");
	int boucle=1,r=0,j=0,u=0;
	TTF_Init();
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);
	SDL_Color couleur = {226, 206, 206}, couleur2 = {126,106,106};
	police = TTF_OpenFont("fonts/Takota.ttf", 70);
	pospicnew.x=280;
	pospicnew.y=100;
	posmulti.x=770;
	posmulti.y=100;
	posbackgr.x=0;
	posbackgr.y=0;
	posnewg.x=210;
	posnewg.y=500;
	pospicmulti.x=860;
	pospicmulti.y=500;
	posback.x=600;
	posback.y=650;
	SDL_BlitSurface(backgr,NULL,ecran,&posbackgr);
	picnew =IMG_Load ("image/perso/newgame.png");
	picmulti =IMG_Load ("image/perso/multi.png");
	newg = TTF_RenderText_Blended(police, "1: NEW GAME", couleur);
	multi = TTF_RenderText_Blended(police, "2: MULTI", couleur);
	back = TTF_RenderText_Blended(police, "0: BACK", couleur);
	
	SDL_BlitSurface(picnew,NULL,ecran,&pospicnew);
	SDL_BlitSurface(picmulti,NULL,ecran,&posmulti);
	SDL_BlitSurface(newg,NULL,ecran,&posnewg);
	SDL_BlitSurface(multi,NULL,ecran,&pospicmulti);
	SDL_BlitSurface(back,NULL,ecran,&posback);
	SDL_Flip(ecran);
	int x,y,son=0;
	SDL_Delay(800);
	while ((*continuer) && boucle )
	{
		SDL_GetMouseState(&x,&y);
		while (SDL_PollEvent(&event))
    		switch(event.type)
    		{
    			case SDL_QUIT:
    			*continuer=0;
    			break;
    			 
    			case SDL_KEYDOWN:
            		switch (event.key.keysym.sym)
            		{
            			case SDLK_KP1:
            			debut(ecran);
				stage0(ecran,continuer,intro,effet,effet2,musique,mute,posvolb,sonspell);
				if (*continuer==1)
				{
					stage1(ecran,continuer,intro,effet,effet2,musique,mute,posvolb,sonspell,dying,hit,victory);
               			}
               			if ((*victory)==1)
               			{
               				stage2(ecran,continuer,intro,effet,effet2,musique,mute,posvolb,sonspell,dying,hit,victory);
               			}
            			break;
            			
            			case SDLK_KP2:
            			Multi(ecran,continuer,intro,effet,effet2,musique,mute,posvolb,sonspell,dying,hit);
            			break;
            			
            			case SDLK_KP0:
            			boucle=0;
            			break;
            		}
            
    		}
//condition :soit clicker sur new game ou continuer
    		if (hover(pospicnew,x,y)==1 || hover(posnewg,x,y)==1)
    		//mono joueur
{
    			TTF_SetFontStyle(police, TTF_STYLE_UNDERLINE);
			newg = TTF_RenderText_Blended(police, "1: NEW GAME", couleur2);

			if (son==0 && *mute==0)
                	{
                  		son=1;
                  		Mix_PlayChannel( -1, effet, 0 ) ;
               		}
//passer pour stage2
               		if(event.button.button == SDL_BUTTON_LEFT)
               		{
               		
               			stage2(ecran,continuer,intro,effet,effet2,musique,mute,posvolb,sonspell,dying,hit,victory);
               		
    		}
    		else if (hover(pospicmulti,x,y)==1 || hover(posmulti,x,y)==1)
    		//multi joueur
{
    			TTF_SetFontStyle(police, TTF_STYLE_UNDERLINE);
    			multi = TTF_RenderText_Blended(police, "2: MULTI", couleur2);
    			if (son==0 && *mute==0)
                	{
                  		son=1;
                  		Mix_PlayChannel( -1, effet, 0 ) ;
               		}
               		if(event.button.button == SDL_BUTTON_LEFT)
               		{
               			Multi(ecran,continuer,intro,effet,effet2,musique,mute,posvolb,sonspell,dying,hit);
               		}
    		}
    		else if (hover(posback,x,y)==1)
    		//back to menu
{
    			TTF_SetFontStyle(police, TTF_STYLE_UNDERLINE);
    			back = TTF_RenderText_Blended(police, "0: BACK", couleur2);
    			if(event.button.button == SDL_BUTTON_LEFT)
    			{
    				boucle=0;
    			}
    		}
    		else 
    		//fixer le menu de nouveau
{

    			son=0;
    			TTF_SetFontStyle(police, TTF_STYLE_NORMAL);
    			newg = TTF_RenderText_Blended(police, "1: NEW GAME", couleur);
    			multi = TTF_RenderText_Blended(police, "2: MULTI", couleur);
			back = TTF_RenderText_Blended(police, "0: BACK", couleur);
    		}
//copier le surface

    		SDL_BlitSurface(backgr,NULL,ecran,&posbackgr);
    		SDL_BlitSurface(picnew,NULL,ecran,&pospicnew);
    		SDL_BlitSurface(picmulti,NULL,ecran,&posmulti);
    		SDL_BlitSurface(newg,NULL,ecran,&posnewg);
		SDL_BlitSurface(multi,NULL,ecran,&pospicmulti);
		SDL_BlitSurface(back,NULL,ecran,&posback);
		SDL_Flip(ecran);	
	}
	
	
