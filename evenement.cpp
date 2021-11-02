#include "evenement.h"

using namespace TIME;

std::ostream& operator<<(std::ostream& f, const Evt& e){
    e.afficher(f);
    return f;
}

void EvtPj::afficher(std::ostream& f) const {
    f<<"***** EvtPj ********"<<"\n";
}

void Evt1j::afficher(std::ostream& f) const {
    f<<"***** Evt ********"<<"\n"<<"Date="<<date<<"\n";
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

Evt1j* Evt1j::clone() const { return new Evt1j(*this); }
Evt1jDur* Evt1jDur::clone() const { return new Evt1jDur(*this); }
Rdv* Rdv::clone() const { return new Rdv(*this); }
EvtPj* EvtPj::clone() const { return new EvtPj(*this); }


Agenda& Agenda::operator<<(Evt& e) {
    tab.push_back(e.clone());
    return *this;
}

void Agenda::afficher(std::ostream& f) const{
    f<<"##### AGENDA #####"<<"\n";
    for(unsigned int i=0; i<tab.size(); i++) { tab[i]->afficher(f); }
    f<<"##### FIN AGENDA #####"<<"\n";
}

Agenda::~Agenda(){
    for (unsigned int i = 0; i < tab.size(); i++)
        delete tab[i];
}