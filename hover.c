#include "hover.h"

//collision lors du click sur les button de menu
int hover(SDL_Rect pos,int x,int y){ //b box
    Uint8 p;
    if((x >= pos.x) && (x <= pos.x + pos.w) && ( y >= pos.y) && (y <= pos.y + pos.h)) return 1;
    else return 0;
}
