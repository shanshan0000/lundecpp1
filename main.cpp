#include <iostream>
#include "fonction.h"

using namespace std;

int main() {
    Integers a;

    for(Integers::Iterator it = a.begin(); it != a.end(); ++ it)
    {
        cout << *it << endl;
    }

    return 0;
}
