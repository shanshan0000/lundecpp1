#include <iostream>
#include "header.h"


int main() {
    A::getInstance().func();
    A::getInstance().func();
    A::libererInstance();

    return 0;
}
