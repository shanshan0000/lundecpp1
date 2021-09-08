#include "fonction.h"

int main() {
    N1::bonjour();
    N2::bonjour();

    using namespace N1;
    bonjour();

    N2::bonjour();

    return 0;
}