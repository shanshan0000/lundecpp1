#include "fraction.h"
#include <iostream>

int main(){
    using namespace MATH;
    Fraction f1(3,4);
    Fraction f2(5);
    Fraction f4 = f1 + f2; // utilisation de la fonction

    f1 ++;
    ++ f2;
    
    std::cout << f1 << std::endl;
}