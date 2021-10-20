#include <iostream>
#include "set.h"

using namespace Set;

int main() {
    auto it2a = Jeu::getInstance().getInterator2();
    while(!it2a.isDone()){
        it2a.currentItem();
        it2a.next();
    }

    auto it2b = Jeu::getInstance().getInterator2();
    while(!it2b.isDone()){
        it2b.currentItem();
        it2b.next();
    }

    for(Jeu::Iterator2 it2c = Jeu::getInstance().getInterator2(); !it2c.isDone(); it2c.next())
    {

    }

    for(auto it3a = Jeu::getInstance().begin(); it3a != Jeu::getInstance().end(); ++ it3a){
        *it3a;
    }


    return 0;
}
