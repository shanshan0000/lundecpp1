#include "fraction.h"

int main(){
    MATH::Fraction f1; // utilisation de l’opérateur de résolution de portée
    f1.numerateur=3;
    f1.denominateur=4;
    using namespace MATH; // utilisation d’une using-directive.
    Fraction f2;
}