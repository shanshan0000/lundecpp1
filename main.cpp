#include <iostream>
#include "fonction.h"

using namespace std;

int main() {
    Integers a;

    Integers::Iterator it = a.getIterator();

    while(!it.isDone())
    {
        cout << it.currentItem() << endl;
        it.next();
    }

    return 0;
}
