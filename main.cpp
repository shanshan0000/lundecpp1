#include <iostream>
#include "evenement.h"


int main() {
    using namespace std;
    using namespace TIME;
    Rdv* pt5= new Rdv(Date(12,11,2013),"reunion UV",Horaire(17,30),Duree(60),"Intervenants UV","bureau");
    pt5->afficher();
    delete pt5;
    Evt1j* pt6= new Rdv(Date(12,11,2013),"reunion UV",Horaire(17,30),Duree(60),"Intervenants UV","bureau");
    pt6->afficher();
    delete pt6;
    return 0;
}
