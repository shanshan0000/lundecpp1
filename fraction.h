#ifndef CPP_FRACTION_H
#define CPP_FRACTION_H

#include<iostream> // nécessaire pour utiliser les objets \cc{ostream}
#include <cstring>

namespace MATH {
    class Fraction {
    private:
        int numerateur;
        int denominateur;
        void simplification();
    public:
        // accesseurs en lecture
        int getNumerateur() const { return numerateur; }
        int getDenominateur() const { return denominateur; }

        // accesseur en écriture (édition)
        void setFraction(int n, int d);

        Fraction& operator++(); // version préfixe
        const Fraction operator++(int); // version postfixe

        Fraction(int n=0, int d=1);
        ~Fraction(){};
    };

    class FractionException {
    private:
        char info[256];

    public:
        FractionException(const char* str){ std::strcpy(info,str); }
        const char* getInfo() const { return info; }
    };

    const Fraction operator+(const Fraction& f1, const Fraction& f2);
}

std::ostream& operator<<(std::ostream& F, const MATH::Fraction& frac);

#endif //CPP_FRACTION_H
