#include "fonction.h"

/*
void init(point* pt, int _x, int _y, int _z) {
    pt->x=_x; pt->y=_y; pt->z=_z;
}

void init(point* pt, int _x, int _y) {
    pt->x=_x; pt->y=_y; pt->z=0;
}

void init(point* pt, int _x) {
    pt->x=_x; pt->y=0; pt->z=0;
}

void init(point* pt) {
    pt->x=0; pt->y=0; pt->z=0;
}
*/

void init(point& pt, int _x, int _y, int _z) {
    pt.x=_x; pt.y=_y; pt.z=_z;
}

void init(point* pt, int _x, int _y, int _z) {
    pt->x=_x; pt->y=_y; pt->z=_z;
}

// alternative méthode de classe
void point::init(int _x, int _y, int _z) {
    x = _x; y = _y; z = _z;
}

