#include <iostream>
#include "header.h"


int main() {
    A::n = 9;
    A::n += 10;

    A a;
    a.n = 99;

    A b;
    b.n = 88;

    std::cout << A::n << std::endl;
    std::cout << a.n << std::endl;

    return 0;
}
