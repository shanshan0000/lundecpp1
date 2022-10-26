#include "evenement.h"

using namespace TIME;

std::ostream &operator<<(std::ostream &f, const Evt1j &e) {
    e.afficher(f);
    return f;
}

void Evt1j::afficher(std::ostream &f) const {
    f << "***** Evt ********" << "\n" << "Date=" << date << " sujet=" << sujet << "\n";
}


void Evt1jDur::afficher(std::ostream &f) const {
    //f<<"***** Evt ********"<<"\n"<<"Date="<<date<<" sujet="<<sujet<<"\n";
    Evt1j::afficher(f); // rappel de la méthode de la classe de base.
    f << "debut=" << debut << " duree=" << duree << "\n";
}

void Rdv::afficher(std::ostream &f) const {
    Evt1jDur::afficher(f); // rappel de la méthode de la classe de base.
    f << "personne(s)=" << personne << " lieu=" << lieu << "\n";
}

TIME::Agenda &TIME::Agenda::operator<<(TIME::Evt1j &e) {
    tab.push_back(&e);
    return *this;
}

void TIME::Agenda::afficher(std::ostream &f) const {
    f << "##### AGENDA #####" << "\n";
    for (unsigned int i = 0; i < tab.size(); i++) { tab[i]->afficher(f); }
    f << "##### FIN AGENDA #####" << "\n";
}

TIME::Agenda::~Agenda() {}