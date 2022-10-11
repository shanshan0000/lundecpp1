#include "set.h"

namespace Set {
    std::initializer_list<Couleur> Couleurs = { Couleur::rouge, Couleur::mauve, Couleur::vert };
    std::initializer_list<Nombre> Nombres = { Nombre::un, Nombre::deux, Nombre::trois };
    std::initializer_list<Forme> Formes = { Forme::ovale, Forme::vague, Forme::losange };
    std::initializer_list<Remplissage> Remplissages = { Remplissage::plein, Remplissage::vide, Remplissage::hachure };

    string toString(Couleur c) {
        switch (c) {
            case Couleur::rouge: return "R";
            case Couleur::mauve: return "M";
            case Couleur::vert: return "V";
            default: throw SetException("Couleur inconnue");
        }
    }

    string toString(Nombre v) {
        switch (v) {
            case Nombre::un: return "1";
            case Nombre::deux: return "2";
            case Nombre::trois: return "3";
            default: throw SetException("Nombre inconnue");
        }
    }

    string toString(Forme f) {
        switch (f) {
            case Forme::ovale: return "O";
            case Forme::vague: return "~";
            case Forme::losange: return "\004";
            default: throw SetException("Forme inconnue");
        }
    }

    string toString(Remplissage r) {
        switch (r) {
            case Remplissage::plein: return "P";
            case Remplissage::vide: return "_";
            case Remplissage::hachure: return "H";
            default: throw SetException("Remplissage inconnu");
        }
    }

    std::ostream& operator<<(std::ostream& f, Couleur c) { f << toString(c); return f; }
    std::ostream& operator<<(std::ostream& f, Nombre v) {	f << toString(v); return f; }
    std::ostream& operator<<(std::ostream& f, Forme x) { f << toString(x);  return f; }
    std::ostream& operator<<(std::ostream& f, Remplissage r) { f << toString(r); return f; }

    void printCouleurs(std::ostream& f) {
        for (auto c : Couleurs) f << c << " ";
        f << "\n";
    }

    void printNombres(std::ostream& f) {
        for (auto v : Nombres) f << v << " ";
        f << "\n";
    }

    void printFormes(std::ostream& f) {
        for (auto x : Formes) f << x << " ";
        f << "\n";
    }

    void printRemplissages(std::ostream& f) {
        for (auto r : Remplissages) f << r << " ";
        f << "\n";
    }

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

    Pioche::Pioche(const Jeu& j) :cartes(new const Carte*[j.getNbCartes()]), nb(j.getNbCartes()) {
        for (size_t i = 0; i < nb; i++) cartes[i] = &(j.getCarte(i));
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

    void Plateau::ajouter(const Carte& c) {
        if (nb == nbMax) {
            const Carte** newtab = new const Carte*[(nbMax + 1) * 2];
            for (size_t i = 0; i < nb; i++) newtab[i] = cartes[i];
            auto old = cartes;
            cartes = newtab;
            nbMax = (nbMax + 1) * 2;
            delete[] old;
        }
        cartes[nb++] = &c;
    }

    void Plateau::retirer(const Carte& c) {
        size_t i = 0;
        while (i < nb && cartes[i] != &c) i++;
        if (i == nb) throw SetException("Carte inexistante");
        i++;
        while (i < nb) {
            cartes[i - 1] = cartes[i]; i++;
        }
        nb--;
    }

    void Plateau::print(ostream& f) const {
        for (size_t i = 0; i < nb; i++) {
            if (i % 4 == 0) f << "\n";
            f << *cartes[i] << " ";
        }
        f << "\n";
    }

    ostream& operator<<(ostream& f, const Plateau& m) {
        m.print(f);
        return f;
    }

    Plateau::Plateau(const Plateau& p):cartes(new const Carte*[p.nb]),nb(p.nb),nbMax(p.nb) {
        for (size_t i = 0; i < nb; i++) cartes[i] = p.cartes[i];
    }

    Plateau& Plateau::operator=(const Plateau& p) {
        if (this != &p) {
            if (p.nb > nbMax) {
                const Carte **newtab = new const Carte *[p.nb];
                for (size_t i = 0; i < nb; i++) newtab[i] = p.cartes[i];
                auto old = cartes;
                cartes = newtab;
                nb = nbMax = p.nb;
                delete[] old;
            } else {
                for (size_t i = 0; i < nb; i++) cartes[i] = p.cartes[i];
                nb = p.nb;
            }
        }
        return *this;
    }


}