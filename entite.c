#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "entite.h"

void initialiser_entite_secondaire (entite_secondaire entite[],int n) 

{
	
	int i ; 
  for ( i = 0; i < n; i++)
  {
  	entite[i].position_max_x=0;
  	entite[i].position_min_x=0;
  	entite[i].frameup=0;
  	entite[i].framedown=0;
  	entite[i].frameleft=0;
  	entite[i].frameright=0;
	entite[i].position_aleatoire_max_x=0;
	entite[i].position_aleatoire_max_y=0;
	entite[i].position_aleatoire_min_x=0;
	entite[i].position_aleatoire_min_y=0;
  	entite[i].position_min_y=0;
  	entite[i].position_max_y=0;
  	entite[i].position_entite.x=0 ; 
  	entite[i].position_entite.y=0 ; 
	entite[i].pos_affichage.x=0;
	entite[i].pos_affichage.y=0;
	entite[i].position_map.x=0;
	entite[i].position_map.y=0;
	entite[i].curframe=0;
	entite[i].maxframe=0;
	entite[i].choix=i;
	entite[i].frame.y=0;
	entite[i].frame.x=0;
	entite[i].frame.h=0;
	entite[i].frame.w=0;
	if (i==2)
	{
        entite[i].frameup=0;
  	entite[i].framedown=0;
  	entite[i].frameleft=0;
  	entite[i].frameright=0;
	entite[i].maxframe=6;
	entite[i].frame.h=60;
	entite[i].frame.w=60;	
	}
	if (i==3)
	{
        entite[i].frame.x=48;
	entite[i].frame.h=48;
	entite[i].frame.w=48;
        entite[i].frame.y=96;

	}
	sprintf(entites,"entite/%d.png",i);

  	entite[i].affichage_secondaire=IMG_Load(entites); 
}
}

void animation_entite(entite_secondaire *entite )
{
			
entite->curframe+=1;

	if(entite->curframe>entite->maxframe)
	{
		entite->curframe=0;
	}

entite->frame.x=entite->curframe*entite->frame.w;
SDL_Delay(15);
}
