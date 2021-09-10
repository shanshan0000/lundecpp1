#include <iostream>
#include "fraction.h"

void MATH::Fraction::setFraction(int n, int d) {
    numerateur=n; denominateur=d;
    if (d==0) {
        std::cerr<<"erreur : denominateur nul\n";
        denominateur=1;
    }
    simplification();
}

MATH::Fraction::Fraction(int n, int d):numerateur(n),denominateur(d) {
    if (denominateur==0){
        std::cerr<<"erreur: denominateur=0\n";
        denominateur=1;
    }
    simplification();
}

void MATH::Fraction::simplification(){
    if (numerateur==0) {
        denominateur=1;
        return;
    }
    if (denominateur==0)
        return;
    auto a=numerateur, b=denominateur;
    if (a<0) a=-a;
    if (b<0) b=-b;
    while(a!=b){
        if (a>b)
            a=a-b;
        else
            b=b-a;
    }
    numerateur/=a;
    denominateur/=a;
    if (denominateur<0) {
        denominateur=-denominateur;
        numerateur=-numerateur;
    }
}

const MATH::Fraction MATH::Fraction::somme(const MATH::Fraction& f) const {
    return Fraction(numerateur*f.denominateur+f.numerateur*denominateur,
                    denominateur*f.denominateur);
}