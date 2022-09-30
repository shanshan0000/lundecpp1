#include <iostream>
#include "set.h"

using namespace Set;

int main() {
    Carte a{Couleur::vert, Nombre::trois, Forme::ovale, Remplissage::hachure};
    Carte b(a);
    Carte c{a};

    Carte d{Couleur::rouge, Nombre::trois, Forme::ovale, Remplissage::hachure};
    d = c;




    std::cin.get();
    return 0;
}
