#ifndef CPP_FRACTION_H
#define CPP_FRACTION_H


namespace MATH {
    class Fraction {
    private:
        int numerateur;
        int denominateur;
        void ____();
    public:
        // accesseurs en lecture
        int ____() const { return numerateur; }
        int ____() const { return denominateur; }

        // accesseur en écriture (édition)
        void setFraction(int n, int d);

        Fraction(int n=0, int d=1);
    };

}


#endif //CPP_FRACTION_H
