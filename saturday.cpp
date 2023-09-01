#include "fonction.h"

int fct(int x, float y){ std::cout<<"3:"<<x<<y<<"\n"; return 0; }
float fct(float x, int y){ std::cout<<"4:"<<x<<y<<"\n"; return 3.14; }

int fct(int x, double y){ std::cout<<"6:"<<x<<y<<"\n"; return 0; }
