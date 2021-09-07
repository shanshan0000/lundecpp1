#include "fonction.h"

int fct(int x){ std::cout<<"1:"<<x<<"\n"; return 0; }
int fct(float y){ std::cout<<"2:"<<y<<"\n"; return 0; }
int fct(int x, float y){ std::cout<<"3:"<<x<<y<<"\n"; return 0; }
float fct(float x, int y){ std::cout<<"4:"<<x<<y<<"\n"; return 3.14; }

void exercice_surcharge(){
    int i = 3, j = 15;
    float x = 3.14159, y = 1.414;
    char c = 'A';
    double z = 3.14159265;
    fct(i); //appel 1->surcharge 1
    fct(x); //appel 2->surcharge 2
    fct(i, y); //appel 3->surcharge 3
    fct(x, j); //appel 4->surcharge 4
    fct(c); //appel 5->surcharge 1 avec conversion implicite char->int
    fct(static_cast<int>(c)); // ->surcharge 1 avec conversion explicite C++
    fct((int)c); // ->surcharge 1 avec conversion explicite C (à éviter)
//fct(i, j); //appel 6 ->ambiguïté
    fct(static_cast<float>(i), j); //surcharge 4
    fct(i, static_cast<float>(j)); //surcharge 3
//fct(i, c); //appel 7 ->ambiguïté
    fct(static_cast<float>(i), c); //surcharge 4
    fct(i, z); //appel 8->surcharge 3 avec conversion implicite double->float
//fct(z, z); //appel 9 ->ambiguïté
    fct(static_cast<int>(z), z); //surcharge 4
}