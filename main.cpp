#include <iostream>
#include "evenement.h"


int main() {
    using namespace std;
    using namespace TIME;
    Evt1jDur e3(Date(11,6,2013),"Lancement de Longue Marche",Horaire(17,38),
            Duree(0,10));
    return 0;
}
