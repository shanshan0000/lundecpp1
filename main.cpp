#include <iostream>
#include "header.h"


int main() {
    A::n = 9;
    A::n += 10;

    A obj;
    obj.m = 77;

    A a;
    a.n = 99;

    A b;
    b.n = 88;
    b.m = 1777;

    std::cout << A::n << std::endl;
    std::cout << a.n << std::endl;
    std::cout << obj.m << std::endl;
    std::cout << a.m << std::endl;
    std::cout << b.m << std::endl;

    return 0;
}
