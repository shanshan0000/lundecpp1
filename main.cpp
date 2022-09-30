#include <iostream>
#include "set.h"

using namespace Set;

int main() {

    Jeu a;
    Jeu b(a);

    Jeu c;
    c = a;

    std::cin.get();
    return 0;
}
