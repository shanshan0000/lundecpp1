#ifndef CPP_FONCTION_H
#define CPP_FONCTION_H

#include <iostream>

____ void bonjour()
{
    std::cout << "Zaoshang hao\n";
}


____ N1 {
    void bonjour();

    ____ N3{
        void bonjour();
    }
}

____ N2 {
    void bonjour();
}

#endif //CPP_FONCTION_H
