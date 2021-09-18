#include "evenement.h"

using namespace TIME;

std::ostream& operator<<(std::ostream& f, const Evt1j& e){
    e.afficher(f);
    return f;
}

void Evt1j::afficher(std::ostream& f) const {
    f<<"***** Evt ********"<<"\n"<<"Date="<<date<<" sujet="<<sujet<<"\n";
}


void Evt1jDur::afficher(std::ostream& f) const {
    //f<<"***** Evt ********"<<"\n"<<"Date="<<date<<" sujet="<<sujet<<"\n";
    Evt1j::afficher(f); // rappel de la méthode de la classe de base.
    f<<"debut="<<debut<<" duree="<<duree<<"\n";
}

void Rdv::afficher(std::ostream& f) const {
    Evt1jDur::afficher(f); // rappel de la méthode de la classe de base.
    f<<"personne(s)="<<personne<<" lieu="<<lieu<<"\n";
}

Evt1j::~Evt1j()
{
    std::cout << "destruction d'un objet de la classe Evt1j" << std::endl;
}

Evt1jDur::~Evt1jDur()
{
    std::cout << "destruction d'un objet de la classe Evt1jDur" << std::endl;
}

Rdv::~Rdv()
{
    std::cout << "destruction d'un objet de la classe Rdv" << std::endl;
}
