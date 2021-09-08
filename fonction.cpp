#include "fonction.h"

using namespace std;

namespace N1 {
    void bonjour() {
        cout << "nichao\n";
    }

    namespace N3{
        void bonjour() {
            cout << "Chiao\n";
        }
    }
}

void N2::bonjour() {
    cout<<"hello\n";
}

