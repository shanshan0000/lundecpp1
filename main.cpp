#include "fonction.h"

int main() {
    compte tab[4]={ {"courant", 0},
                    {"codevi", 1500 },
                    {"epargne", 200 },
                    { "cel", 300 }
    };
    operation(tab,"courant")=100;
    operation(tab,"codevi")+=100;
    operation(tab,"cel")-=50;
    for(int i=0; i<4; i++) cout<<tab[i].id<<" : "<<tab[i].solde<<"\n";

    return 0;
}
