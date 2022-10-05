#ifndef CPP_FRACTION_H
#define CPP_FRACTION_H


namespace MATH {
    class Fraction {
    private:
        int numerateur;
        int denominateur;
    public:
        // accesseurs en lectureint getNumerateur() const { return numerateur; }
        int getDenominateur() const { return denominateur; }

        // accesseur en écriture (édition)
        void setFraction(int n, int d);

        Fraction(int n, int d) { setFraction(n,d); }
        Fraction(int n) { setFraction(n,1); }
        Fraction() { setFraction(0,1); } // éviter denominateur=0
    };

}


#endif //CPP_FRACTION_H
