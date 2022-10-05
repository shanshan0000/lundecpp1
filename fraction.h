#ifndef CPP_FRACTION_H
#define CPP_FRACTION_H


// See the answer at Readme.md

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

        Fraction(int n=0, int d=1);
        ~Fraction(){};
    };

    const Fraction operator+(const Fraction& f1, const Fraction& f2);
}

// See the answer at Readme.md

#endif //CPP_FRACTION_H
