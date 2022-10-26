#include <iostream>
#include "evenement.h"


int main() {
    using namespace std;
    using namespace TIME;
    Evt1jDur e3(Date(11,6,2013),"Lancement de Longue Marche",
            Horaire(17,38),Duree(0,10));
    Rdv e4(Date(11,4,2013),"reunion UV",
            Horaire(17,30),Duree(60),
            "Intervenants UV","bureau");
    Evt1j* pt3=&e3;
    Evt1j* pt4=&e4;
    pt3->afficher();
    pt4->afficher();
    return 0;
}
