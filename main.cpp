#include <iostream>
#include "RandomIntGenerator.h"

int main() {

    OBJECT_ADAPTER::RandomIntGenerator r(5000);
    std::cout << r.GetNumber() << std::endl;
    std::cout << r.GetNumber() << std::endl;
    std::cout << r.GetNumber() << std::endl;
    std::cout << r.GetNumber() << std::endl;
    std::cout << r.GetNumber() << std::endl;

    CLASS_ADAPTER::RandomIntGenerator c(8);
    std::cout << c.GetNumber() << std::endl;
    std::cout << c.GetNumber() << std::endl;
    std::cout << c.GetNumber() << std::endl;
    std::cout << c.GetNumber() << std::endl;
    std::cout << c.GetNumber() << std::endl;



    return 0;
}
