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

    Pioche::Pioche(const Jeu& j) :cartes(new const Carte*[j.getNbCartes()]), nb(j
                                                                                        .getNbCartes()) {
        for (size_t i = 0; i < nb; i++) cartes[i] = &j.getCarte(i);
    }
    const Carte& Pioche::piocher() {
        if (nb == 0) throw SetException("Pioche vide");
        size_t x = rand() % nb; // on tire une position entre 0 et nb-1
        const Carte* c = cartes[x]; // on retient l’adresse
        for (size_t i = x + 1; i < nb; i++)
            cartes[i - 1] = cartes[i]; // on décale toutes les cartes aux rangs suivants
        nb--;
        return *c;
    }

    Pioche::~Pioche() {
        delete[] cartes;
    }


    ostream& operator<<(ostream& f, const Carte& c) {
        f << "(" << c.getNombre() << "," << c.getCouleur()<<"," <<c.getForme()<<","
          << c.getRemplissage() << ")";
        return f;
    }

}