#include <iostream>
#include "set.h"

using namespace Set;

int main() {
    Jeu::Iterator_2& it = Jeu::getInstance().getIterator();
    while(!it.isDone()){
        cout << it.currentItem();
        it.next();
    }

    for (auto it2 = Jeu::getInstance().getIterator(); !it2.isDone(); it2.next()) {
        it2.currentItem();
    }

    std::cin.get();
    return 0;
}
