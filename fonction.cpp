#include "fonction.h"

void raz(TD1::essai* e){
    e->n=0;
    e->x=0; // équivalent à (*e).x=0;
}

void raz(TD1::essai& e){
    e.n=0; e.x=0;
}