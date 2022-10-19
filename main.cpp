#include <iostream>
#include "fonction.h"

using namespace std;

int main() {
    Integers a;

    for(auto it = a.begin(); it != a.end(); ++ it)
    {
        *it += 3;
        cout << *it << endl;
    }

    return 0;
}
