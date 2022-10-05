#ifndef CPP_FONCTION_H
#define CPP_FONCTION_H

struct point {
    int x;
    int y;
    int z;
// alternative avec une méthode de classe
    void init(int _x = 0, int _y = 0, int _z = 0);
};

void init(point& pt, int _x=0, int _y=0, int _z=0);

void init(point* pt, int _x=0, int _y=0, int _z=0);


#endif //CPP_FONCTION_H
