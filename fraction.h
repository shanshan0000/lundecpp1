#ifndef CPP_2021_FRACTION_H
#define CPP_2021_FRACTION_H


namespace MATH {
    class Fraction {
    private:
        int numerateur = 0;
        int denominateur = 1;
    public:
        // accesseurs en lectureint getNumerateur() const { return numerateur; }
        int getDenominateur() const { return denominateur; }

        // accesseur en écriture (édition)
        void setFraction(int n, int d);

        Fraction(int n, int d):numerateur(n),denominateur(d) {
            if (denominateur==0) {
                std::cerr<<"erreur : denominateur nul\n";
                denominateur=1;
            }
        }
        Fraction(int n):numerateur(n){} // denominateur=1
        Fraction()= default; // numerateur=0, denominateur=1
    };

}


#endif //CPP_2021_FRACTION_H
