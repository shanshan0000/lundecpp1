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

const MATH::Fraction MATH::operator+(const MATH::Fraction& f1, const MATH::
Fraction& f2){
    return MATH::Fraction(f1.getNumerateur()*f2.getDenominateur()
                          +f2.getNumerateur()*f1.getDenominateur(),
                          f1.getDenominateur()*f2.getDenominateur());
}

// For more information, see Readme.md

MATH::Fraction& MATH::Fraction::operator++() {
    setFraction(getNumerateur()+getDenominateur(),getDenominateur());
    return *this;
}

const MATH::Fraction MATH::Fraction::operator++(int){
    Fraction f(getNumerateur(), getDenominateur()); // copie de la fraction
    setFraction(getNumerateur()+getDenominateur(),getDenominateur());
    return f;
}

// For more information, see Readme.md
