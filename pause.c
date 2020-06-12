//sous menu de sauvegarde
void Pause1(SDL_Surface *ecran,Sint16 *poshero,Sint16 /*(listes des coordonnées) */ *posmagicien,Sint16 *posenigme1,Sint16 *poshpup,Sint16 *posback,Sint16 *pospolice,SDL_Rect *pose1,SDL_Rect *pose2,SDL_Rect *pose3 ,SDL_Rect *pose4 ,SDL_Rect *pose5 ,SDL_Rect *pose6 ,SDL_Rect *pose7 ,Sint16 *posrock1,Sint16 *postrap1,Sint16 *posterre3,Sint16 *posterre1, Sint16 *posterre2, Sint16 *posterre4, Sint16 *posterre5, Sint16 *posterre6, Sint16 *posterre7, Sint16 *posterre8, Sint16 *posterre9, int *camera,int *continuer, int tsec, int tmin, int hp, int cmpsc )

{
SDL_Surface *pause=NULL,*confirm=NULL,*cancel=NULL,*confirm2=NULL,*cancel2=NULL,*Confirm=NULL,*Cancel=NULL;
SDL_Rect pospause,posconfirm,poscancel;
pospause.x=350;
pospause.y=150;
posconfirm.x=500;
posconfirm.y=350;
poscancel.x=800;
poscancel.y=350;
int boucle=1;
int x=0,y=0,couleur1=0,couleur2=0,tmp=0,postmp[36];
SDL_Event event;
FILE* fichier = NULL;
FILE* fichier2 = NULL;
postmp[0]=*poshero;
postmp[1]=*posmagicien;
postmp[2]=*posenigme1;
postmp[3]=*poshpup;
postmp[4]=*posback;
postmp[5]=*pospolice;
postmp[6]=pose1->x;
postmp[7]=pose2->x;
postmp[8]=pose3->x;
postmp[9]=pose4->x;
postmp[10]=pose5->x;
postmp[11]=pose6->x;
postmp[12]=pose7->x;
postmp[13]=*posrock1;
postmp[14]=*postrap1;
postmp[15]=*posterre3;
postmp[16]=*posterre1;
postmp[17]=*posterre2;
postmp[18]=*posterre4;
postmp[19]=*posterre5;
postmp[20]=*posterre6;
postmp[21]=*posterre7;
postmp[22]=*posterre8;
postmp[23]=*posterre9;
postmp[24]=*camera;
postmp[25]=pose1->y;
postmp[26]=pose2->y;
postmp[27]=pose3->y;
postmp[28]=pose4->y;
postmp[29]=pose5->y;
postmp[30]=pose6->y;
postmp[31]=pose7->y;
postmp[32]=tsec;
postmp[33]=tmin;
postmp[34]=hp;
postmp[35]=cmpsc;
	pause=IMG_Load("image/stage/pause.png");
	confirm=IMG_Load("image/stage/confirm.png");
	cancel=IMG_Load("image/stage/cancel.png");
	cancel2=IMG_Load("image/stage/canncel.png");
	confirm2=IMG_Load("image/stage/confim.png");
Confirm=confirm;
Cancel=cancel;
while (boucle)
{
	while (SDL_PollEvent(&event))
		SDL_GetMouseState(&x,&y);
		if (hover(posconfirm, x, y))
		{
			Confirm=confirm2;
			couleur1=1;
			if (event.button.button == SDL_BUTTON_LEFT)
			{
				fichier = fopen("xsauvegarde.txt", "w");
    			if (fichier != NULL)
    			{
    				for (int i=0; i<36; i++)
    				{
    					tmp=(int)postmp[i];
        				fprintf(fichier, "%d ", tmp);
    				}
    				fclose(fichier);
   				fichier2 = fopen("Xstage", "w");
				if (fichier2 != NULL)
				{
					fprintf(fichier, "1");
				}
				fclose(fichier2);
				boucle=0;
			}
   		}
	}
		else
		couleur1=0;
		if (hover(poscancel, x, y))
		{	
			couleur2=1;
			Cancel=cancel2;
			if (event.button.button == SDL_BUTTON_LEFT)
			boucle=0;
		}
		else
		couleur2=0;
        	switch(event.type)
        	{
		case SDL_KEYDOWN:
        	    switch (event.key.keysym.sym)
            	{
            	case SDLK_ESCAPE:
               	 boucle= 0;
                break;
               }

	}
	if (couleur1==1)
	{
		Confirm=confirm2;
	}
	else
	{
		Confirm=confirm;
	}
	if (couleur2==1)
	{
		Cancel=cancel2;
	}
	else
	{
		Cancel=cancel;
	}
	SDL_BlitSurface(pause,NULL,ecran,&pospause);
	SDL_BlitSurface(Confirm,NULL,ecran,&posconfirm);
	SDL_BlitSurface(Cancel,NULL,ecran,&poscancel);
	SDL_Flip(ecran);
	}
}

