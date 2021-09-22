#ifndef CPP_2021_SET_H
#define CPP_2021_SET_H

#include <iostream>

using namespace std;

namespace Set {
    enum Couleur { rouge, violet, vert };
    enum Nombre { un, deux, trois };
    enum Forme { ovale, vague, losange };
    enum Remplissage { plein, hachure, vide };

    static const Couleur Couleurs[] = { rouge, violet, vert };
    static const Nombre Nombres[] = {un, deux, trois };
    static const Forme Formes[] = { ovale, vague, losange };
    static const Remplissage Remplissages[] = { plein, hachure, vide };

    class Carte {
    public:
        Carte(Couleur c, Nombre v, Forme f, Remplissage r) :couleur(c), nombre(v),
                                                            forme(f), remplissage(r) {}
        Couleur getCouleur() const { return couleur; }
        Nombre getNombre() const { return nombre; }
        Forme getForme() const { return forme; }
        Remplissage getRemplissage() const { return remplissage; }
        ~Carte() = default; // optionnel
        Carte(const Carte& c) = default; // optionnel
        Carte& operator=(const Carte& c) = default; // optionnel
    private:
        Couleur couleur;
        Nombre nombre;
        Forme forme;
        Remplissage remplissage;
    };

    class Jeu {
    public:
        Jeu();
        ~Jeu();
        Jeu(const Jeu& j) = delete;
        Jeu& operator=(const Jeu& j) = delete;
        size_t getNbCartes() const
        {
            return 81;
        }
        const Carte& getCarte(size_t i) const
        {
            if (i >= 81)
                throw SetException("Carte invalide");
            return *cartes[i];
        }
    private:
        const Carte* cartes[81];
    };

    class Pioche {
// désigne un paquet de cartes on l’on ne peut que piocher : prendre une carte au hasard
    public:
        explicit Pioche(const Jeu& j); // construction d’une pioche à partir du jeu
        bool estVide() const { return nb == 0; }
        size_t getNbCartes() const { return nb; }
        const Carte& piocher();
        ~Pioche();
        Pioche(const Pioche& p) = delete;
        Pioche& operator=(const Pioche& p) = delete;
    private:
        const Carte** cartes = nullptr;
        size_t nb = 0;
    };


    ostream& operator<<(ostream& f, const Carte& c);

}





#endif //CPP_2021_SET_H
