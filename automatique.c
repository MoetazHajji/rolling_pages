#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "en.h"
    int equation()
    {
     int x,a,b,c,d,x1,x2,x11,x22;
     a=rand()%50;
     b=rand()%50;
     c=rand()%50;

     d=(b*b)-(4*a*c);

     if(d>0) {x11=(-b-sqrt(d))/2*a;
              x22=(-b+sqrt(d))/2*a;
              }
     if(d==0) {x11=-b/2*a;
              x22=x11;}
     if (d<0) {equation();}
     printf("resoudre cette equation \n %dx²+%dx+%d=0 \n ",a,b,c);
     printf("x1= ");
     scanf("%d",&x1);
     printf("x2= ");
     scanf("%d",&x2);
     if((x1==x11)&&(x2==x22)||(x1==x22)&&(x2==x11))return 1;
     else return 0;
    }
