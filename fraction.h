#ifndef CPP_2021_FRACTION_H
#define CPP_2021_FRACTION_H


namespace MATH {
    class Fraction {
    private:
        int numerateur;
        int denominateur;
        void simplification();
    public:
        // accesseurs en lectureint getNumerateur() const { return numerateur; }
        int getDenominateur() const { return denominateur; }

        // accesseur en écriture (édition)
        void setFraction(int n, int d);

        Fraction(int n=0, int d=1);
    };

}


#endif //CPP_2021_FRACTION_H
