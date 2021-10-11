#ifndef CPP_2021_SET_H
#define CPP_2021_SET_H

#include <iostream>
#include <string>

using namespace std;

namespace Set {
    // caracteristiques
    enum class Couleur { rouge, mauve, vert };
    enum class Nombre { un=1, deux=2, trois=3 };
    enum class Forme { ovale, vague, losange };
    enum class Remplissage { plein, vide, hachure };

    // conversion d'une caracteristique en string
    string toString(Couleur c);
    string toString(Nombre v);
    string toString(Forme f);
    string toString(Remplissage v);

    // ecriture d'une caracteristique sur un flux ostream
    ostream& operator<<(ostream& f, Couleur c);
    ostream& operator<<(ostream& f, Nombre v);
    ostream& operator<<(ostream& f, Forme x);
    ostream& operator<<(ostream& f, Remplissage r);

    // listes contenant les valeurs possibles pour chacune des caracteristiques
    extern std::initializer_list<Couleur> Couleurs;
    extern std::initializer_list<Nombre> Nombres;
    extern std::initializer_list<Forme> Formes;
    extern std::initializer_list<Remplissage> Remplissages;

    // affichage des valeurs possibles pour chaque caracteristiques
    void printCouleurs(std::ostream& f = cout);
    void printNombres(std::ostream& f = cout);
    void printFormes(std::ostream& f = cout);
    void printRemplissages(std::ostream& f = cout);

    class SetException {
    public:
        SetException(const string& i) :info(i) {}
        string getInfo() const { return info; }
    private:
        string info;
    };

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

        static Jeu& getInstance() {
            if (instance == nullptr)
                instance = new Jeu;
            return *instance;
        }

        static void libererInstance() {
            delete instance;
            instance = nullptr;
        }

    private:
        const Carte* cartes[81];

        Jeu();
        ~Jeu();
        Jeu(const Jeu& j) = delete;
        Jeu& operator=(const Jeu& j) = delete;

        static Jeu* instance;

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

    class Plateau {
    public:
        Plateau() = default;
        ~Plateau() { delete[] cartes; }
        size_t getNbCartes() const { return nb; }
        void ajouter(const Carte& c);
        void retirer(const Carte& c);
        void print(ostream& f = cout) const;
        Plateau(const Plateau& p);
        Plateau& operator=(const Plateau& p);
    private:
        const Carte** cartes = nullptr;
        size_t nbMax = 0;
        size_t nb = 0;
    };

    class Combinaison {
    public:
        Combinaison(const Carte& u, const Carte& d, const Carte& t) :c1(&u), c2(&d),
                                                                     c3(&t) {}
        bool estUnSET() const;
        const Carte& getCarte1() const { return *c1; }
        const Carte& getCarte2() const { return *c1; }
        const Carte& getCarte3() const { return *c1; }
        ~Combinaison() = default;
        Combinaison(const Combinaison& c) = default;
        Combinaison& operator=(const Combinaison& c) = default;
    private:
        const Carte* c1;
        const Carte* c2;
        const Carte* c3;
    };

    class Controleur {
    public:
        Controleur();
        void distribuer();
        ~Controleur() { delete pioche; }
        const Plateau& getPlateau() const { return plateau; }
    private:
        Jeu jeu;
        Pioche* pioche=nullptr;
        Plateau plateau;
    };


    ostream& operator<<(ostream& f, const Carte& c);
    ostream& operator<<(ostream& f, const Plateau& m);
    ostream& operator<<(ostream& f, const Combinaison& c);


}





#endif //CPP_2021_SET_H
