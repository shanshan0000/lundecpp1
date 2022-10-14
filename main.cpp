#include <iostream>
#include "header.h"


int main() {
    A& a = A::getInstance();
    a.func();

    return 0;
}
