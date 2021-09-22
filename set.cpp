#include "set.h"

namespace Set {

    // https://stackoverflow.com/questions/261963/how-can-i-iterate-over-an-enum
    Jeu::Jeu() {
        size_t i = 0;
        for (auto c : Couleurs)
            for (auto v : Nombres)
                for (auto f : Formes)
                    for (auto r : Remplissages)
                        cartes[i++] = new Carte(c, v, f, r);
    }

    Jeu::~Jeu() {
        for (size_t i = 0; i < getNbCartes(); i++) delete cartes[i];
    }

    ostream& operator<<(ostream& f, const Carte& c) {
        f << "(" << c.getNombre() << "," << c.getCouleur()<<"," <<c.getForme()<<","
          << c.getRemplissage() << ")";
        return f;
    }

}