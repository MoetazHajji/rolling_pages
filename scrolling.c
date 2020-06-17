
#include "scrolling.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>



void scrolling2 (Sint16 *poshero,Sint16 *posmagicien,Sint16 *posenigme1,Sint16 *poshpup,Sint16 *poshpup1,Sint16 *posback,Sint16 *pospolice,Sint16 *pose1,Sint16 *pose2,Sint16 *pose3 ,Sint16 *pose4 ,Sint16 *pose5 ,Sint16 *pose6 ,Sint16 *pose7 ,Sint16 *pose8 ,Sint16 *posrock1,Sint16 *postrap1,Sint16 *posterre3,Sint16 *posterre1, Sint16 *posterre2, Sint16 *posterre4, Sint16 *posterre5, Sint16 *posterre6, Sint16 *posterre7, Sint16 *posterre8, Sint16 *posterre9,Sint16 *posninjaa, int *camera,SDL_Surface **ecran, SDL_Surface **heroactu, int e)
{
if (e==1)
{
	(*camera)+=speed;
	(*poshero)+=speed;
	if((*poshero)>=1366/3 && (*camera)<1366*7-650) //fixe personnage, deplacement decor
	{
		(*posenigme1)-=speed;
		(*postrap1)-=speed;
		(*posterre1)-=speed;
		(*posterre2)-=speed;
		(*posterre3)-=speed;
		(*posterre4)-=speed;
		(*posterre5)-=speed;
		(*posterre6)-=speed;
		(*posterre7)-=speed;
		(*posterre8)-=speed;
		(*posterre9)-=speed;
		(*posninjaa)-=speed;
		(*poshpup)-=speed;
		(*poshpup1)-=speed;
		(*posmagicien)-=speed;
		(*posrock1)-=speed;
		(*poshero)-=speed;
		(*posback)-=speed;
		(*pospolice)-=speed;
		(*pose1)-=speed;
		(*pose2)-=speed;
		(*pose3)-=speed;
		(*pose4)-=speed;
		(*pose5)-=speed;
		(*pose6)-=speed;
		(*pose7)-=speed;
		(*pose8)-=speed;
	}
	if((*poshero)>=((1366/4)*3 +150)) //collision ecran droite
	{
		(*poshero)-=speed;
		(*camera)-=speed;
	}
}
else if (e==2)
{
	(*camera)-=speed;
	(*poshero)-=speed;
	if((*poshero)<=(*ecran)->w/5)
	{
		(*posenigme1)+=speed;
		(*posterre1)+=speed;
		(*posterre2)+=speed;
		(*posterre3)+=speed;
		(*posterre4)+=speed;
		(*posterre5)+=speed;
		(*posterre6)+=speed;
		(*posterre7)+=speed;
		(*posterre8)+=speed;
		(*posterre9)+=speed;
		(*posninjaa)+=speed;
		(*posmagicien)+=speed;
		(*poshpup)+=speed;
		(*poshpup1)+=speed;
		(*postrap1)+=speed;
		(*posrock1)+=speed;
		(*pose1)+=speed;
		(*pose2)+=speed;
		(*pose3)+=speed;
		(*pose4)+=speed;
		(*pose5)+=speed;
		(*pose6)+=speed;
		(*pose7)+=speed;
		(*pose8)+=speed;
		(*posback)+=speed;
		(*pospolice)+=speed;
		(*poshero)+=speed;
		if((*camera)<0)
		{
			(*poshero)+=speed;
			(*camera)+=speed;
		}
	}
	if ((*posback)>0)
	{	
		(*posenigme1)=9250;
		(*posterre1)=1300;
		(*posterre2)=1800;
		(*posterre3)=2300;
		(*posterre4)=3300;
		(*posterre5)=3800;
		(*posterre6)=4300;
		(*posterre7)=5300;
		(*posterre8)=5800;
		(*posterre9)=6300;
		(*posninjaa)=7500;
		(*posmagicien)=9500;
		(*poshpup)=2360;
		(*poshpup1)=5360;
		(*postrap1)=2800;
		(*posrock1)=500;
		(*pospolice)=800;
		(*pose1)=1000;
		(*pose2)=2000;
		(*pose3)=3000;
		(*pose4)=4000;
		(*pose5)=5000;
		(*pose6)=6000;
		(*pose7)=7000;
		(*pose8)=8000;
		(*posback)=0;
		(*poshero)-=speed;
		if ((*poshero)<0)
		{
			(*poshero)+=speed;
		}
	}
}
}
void scrolling (Sint16 *poshero,Sint16 *posmagicien,Sint16 *posenigme1,Sint16 *poshpup,Sint16 *posback,Sint16 *pospolice,Sint16 *pose1,Sint16 *pose2,Sint16 *pose3 ,Sint16 *pose4 ,Sint16 *pose5 ,Sint16 *pose6 ,Sint16 *pose7 ,Sint16 *posrock1,Sint16 *postrap1,Sint16 *posterre3,Sint16 *posterre1, Sint16 *posterre2, Sint16 *posterre4, Sint16 *posterre5, Sint16 *posterre6, Sint16 *posterre7, Sint16 *posterre8, Sint16 *posterre9, int *camera,SDL_Surface **ecran, SDL_Surface **heroactu, int e)
{
if (e==1)
{
	(*camera)+=speed;
	(*poshero)+=speed;
	if((*poshero)>=1366/3 && (*camera)<1366*5) //fixe personnage, deplacement decor
	{
		(*posenigme1)-=speed;
		(*postrap1)-=speed;
		(*posterre1)-=speed;
		(*posterre2)-=speed;
		(*posterre3)-=speed;
		(*posterre4)-=speed;
		(*posterre5)-=speed;
		(*posterre6)-=speed;
		(*posterre7)-=speed;
		(*posterre8)-=speed;
		(*posterre9)-=speed;
		(*poshpup)-=speed;
		(*posmagicien)-=speed;
		(*posrock1)-=speed;
		(*poshero)-=speed;
		(*posback)-=speed;
		(*pospolice)-=speed;
		(*pose1)-=speed;
		(*pose2)-=speed;
		(*pose3)-=speed;
		(*pose4)-=speed;
		(*pose5)-=speed;
		(*pose6)-=speed;
		(*pose7)-=speed;
	}
	if((*poshero)>=((1366/4)*3 +150)) //collision ecran droite
	{
		(*poshero)-=speed;
		(*camera)-=speed;
	}
}
else if (e==2)
{
	(*camera)-=speed;
	(*poshero)-=speed;
	if((*poshero)<=(*ecran)->w/5)
	{
		(*posenigme1)+=speed;
		(*posterre1)+=speed;
		(*posterre2)+=speed;
		(*posterre3)+=speed;
		(*posterre4)+=speed;
		(*posterre5)+=speed;
		(*posterre6)+=speed;
		(*posterre7)+=speed;
		(*posterre8)+=speed;
		(*posterre9)+=speed;
		(*posmagicien)+=speed;
		(*poshpup)+=speed;
		(*postrap1)+=speed;
		(*posrock1)+=speed;
		(*pose1)+=speed;
		(*pose2)+=speed;
		(*pose3)+=speed;
		(*pose4)+=speed;
		(*pose5)+=speed;
		(*pose6)+=speed;
		(*pose7)+=speed;
		(*posback)+=speed;
		(*pospolice)+=speed;
		(*poshero)+=speed;
		if((*camera)<0)
		{
			(*poshero)+=speed;
			(*camera)+=speed;
		}
	}
	if ((*posback)>0)
	{	
		(*posenigme1)=6700;
		(*posterre1)=1300;
		(*posterre2)=1800;
		(*posterre3)=2300;
		(*posterre4)=3300;
		(*posterre5)=3800;
		(*posterre6)=4300;
		(*posterre7)=5300;
		(*posterre8)=5800;
		(*posterre9)=6300;
		(*posmagicien)=7500;
		(*poshpup)=2360;
		(*postrap1)=2800;
		(*posrock1)=500;
		(*pospolice)=800;
		(*pose1)=1000;
		(*pose2)=2000;
		(*pose3)=3000;
		(*pose4)=4000;
		(*pose5)=5000;
		(*pose6)=6000;
		(*pose7)=7000;
		(*posback)=0;
		(*poshero)-=speed;
		if ((*poshero)<0)
		{
			(*poshero)+=speed;
		}
	}
}
}
