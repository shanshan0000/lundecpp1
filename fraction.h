#ifndef CPP_2021_FRACTION_H
#define CPP_2021_FRACTION_H

#include <iostream>

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

        Fraction(int n=0, int d=1) { setFraction(n,d);
            std::cout<<"construction de la Fraction "<<this<<"\n";
        }
        ~Fraction(){ std::cout<<"destruction de la Fraction "<<this<<"\n"; }
    };

    const Fraction somme(const Fraction& f1, const Fraction& f2);

}


#endif //CPP_2021_FRACTION_H
