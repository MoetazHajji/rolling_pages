#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>

typedef struct entite_secondaire
{
SDL_Rect position_entite;
SDL_Surface *affichage_secondaire;
SDL_Rect frame;
int position_aleatoire_max_x;
int position_aleatoire_max_y;
int position_aleatoire_min_x;
int position_aleatoire_min_y;
int frameup;
int framedown;
int frameleft;
int frameright;
SDL_Rect pos_affichage;
int curframe;
int maxframe;
int choix;
int position_max_x;
int position_min_x;
int position_min_y;
int position_max_y;
} entite_secondaire;

void initialiser_entite_secondaire (entite_secondaire entite[],int n);
void afficher_entite_secondaire (entite_secondaire entite, SDL_Surface *ecran);
void animation_entite(entite_secondaire *entite );
int deplacement_aleatoire ( int positionmax, int positionmin   );
void deplacement_entite_x (entite_secondaire *entite);
void deplacement_entite_y (entite_secondaire *entite); 

#endif








