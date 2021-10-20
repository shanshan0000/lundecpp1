#include <iostream>
#include "set.h"

using namespace Set;

int main() {
    auto it = Jeu::getInstance().getInterator2();
    while(!it.isDone()){
        it.currentItem();
        it.next();
    }

    auto it2 = Jeu::getInstance().getInterator2();
    while(!it2.isDone()){
        it2.currentItem();
        it2.next();
    }

    for(Jeu::Iterator2 it3 = Jeu::getInstance().getInterator2(); !it3.isDone(); it3.next())
    {

    }

    for(Jeu::Iterator3 itt = Jeu::getInstance().begin(); !itt.end(); ++ itt){
        *itt;
    }


    return 0;
}
