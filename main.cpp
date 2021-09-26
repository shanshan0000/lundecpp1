#include "fraction.h"
#include <iostream>

int main(){
    using namespace MATH;
    Fraction f1(3,4);
    std::cout << ( f1 ++ ) << std::endl;
    std::cout << ( f1 ++ ) << std::endl;
    std::cout << ( f1 ) << std::endl;

    Fraction f2(3,4);
    std::cout << ( ++ f2 ) << std::endl;
    std::cout << ( ++ f2 ) << std::endl;
    std::cout << ( f2 ) << std::endl;

    // For more information, see Readme.md
}