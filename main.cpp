#include <iostream>
#include "fonction.h"

using namespace std;

void essai_init() {
    point p;
    p.init(4, 5, 6);
    point *pp = &p;
    pp->init(4, 5, 6);
    point *ppp = new point;
    ppp->init(7, 8);
    delete ppp;
    init(&p);
    init(&p,1);
    init(&p,1,2);
    init(&p,1,2,3);
    init(p);
    init(p,1);
    init(p,1,2);
    init(p,1,2,3);
}

int main() {
    essai_init();
    return 0;
}
