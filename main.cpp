#include <iostream>
#include "fonction.h"

using namespace std;

int main() {
    Integers a;

    Integers::Iterator it = a.getIterator();

    while(it.hasNext())
    {
        cout << it.next() << endl;
    }

    return 0;
}
