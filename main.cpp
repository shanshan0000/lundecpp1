#include <iostream>
#include "fonction.h"

using namespace std;

int main() {
    Integers a;

    for(auto it = a.begin(); it != a.end(); ++ it)
    {
        cout << (*it).value << endl;
    }


    return 0;
}
