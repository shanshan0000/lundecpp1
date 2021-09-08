#include <iostream>
#include "fonction.h"

using namespace std;

void essai_init() {
    point p;
    init(&p);
    init(&p,1);
    init(&p,1,2);
    init(&p,1,2,3);
}

int main() {
    essai_init();
    return 0;
}
