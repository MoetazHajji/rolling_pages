
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "entite.h"
int main()
{
int n=1;
SDL_Surface *ecran=NULL   ;
entite_secondaire entite[0];
SDL_Init(SDL_INIT_EVERYTHING);
entite[0].position_aleatoire_max_y= deplacement_aleatoire (entite[0].position_max_y, entite[0].position_min_y  );
entite[0].position_aleatoire_min_y = deplacement_aleatoire (entite[0].position_max_y, entite[0].position_min_y  );
deplacement_entite_y (&entite[0]);
animation_entite (&entite[0] ) ; 
afficher_entite_secondaire (entite[0], ecran) ;
}


