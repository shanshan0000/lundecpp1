#ifndef CPP_2021_FRACTION_H
#define CPP_2021_FRACTION_H


namespace MATH {
    class Fraction {
    private:
        int numerateur;
        int denominateur;
    public:
        // accesseurs en lecture
        int getNumerateur() const { return numerateur; }
        int getDenominateur() const { return denominateur; }

        // accesseur en écriture (édition)
        void setFraction(int n, int d);
    };

}


#endif //CPP_2021_FRACTION_H
