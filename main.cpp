#include "fraction.h"

int main() {
    using namespace MATH;
    try {
        Fraction B(3, 0);
    }
    catch (const char *e) {
        std::cout << e << "\n";
    }

}