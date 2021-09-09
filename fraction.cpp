#include <iostream>
#include "fraction.h"

void MATH::Fraction::setFraction(int n, int d) {
    numerateur=n;
    denominateur=d;
    if (d==0) {
        std::cerr<<"erreur : denominateur nul\n";
        denominateur=1;
    }
}

