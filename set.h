#ifndef CPP_2021_SET_H
#define CPP_2021_SET_H

#include <iostream>

using namespace std;

namespace Set {
    enum Couleur { rouge, violet, vert };
    enum Nombre { un, deux, trois };
    enum Forme { ovale, vague, losange };
    enum Remplissage { plein, hachure, vide };

    class Carte {
    public:
        Carte(Couleur c, Nombre v, Forme f, Remplissage r) :couleur(c), nombre(v),
                                                            forme(f), remplissage(r) {}
        Couleur getCouleur() const { return couleur; }
        Nombre getNombre() const { return nombre; }
        Forme getForme() const { return forme; }
        Remplissage getRemplissage() const { return remplissage; }
        ~Carte() = default; // optionnel
        Carte(const Carte& c)
        {
            this->nombre = c.nombre;
            this->remplissage = c.remplissage;
            this->forme = c.forme;
            this->couleur = c.couleur;
        }

        Carte& operator=(const Carte& c)
        {
            this->nombre = c.nombre;
            this->remplissage = c.remplissage;
            this->forme = c.forme;
            this->couleur = c.couleur;
            return *this;
        }
    private:
        Couleur couleur;
        Nombre nombre;
        Forme forme;
        Remplissage remplissage;
    };

    std::ostream& operator<<(ostream& f, const Carte& c);

}





#endif //CPP_2021_SET_H
