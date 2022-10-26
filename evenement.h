#ifndef CPP_EVENEMENT_H
#define CPP_EVENEMENT_H

#include <iostream>
#include <string>
#include "timing.h"

namespace TIME{
    class Evt1j {
    private:
        Date date;
        std::string sujet;
    public:
        Evt1j(const Date& d, const std::string& s):date(d),sujet(s){}
        const std::string& getDescription() const { return sujet; }
        const Date& getDate() const { return date; }
        void afficher(std::ostream& f= std::cout) const {
            f<<"***** Evt ********"<<"\n"<<"Date="<<date<<" sujet="<<sujet<<"\n";
        }
    };

    class Evt1jDur : public Evt1j {
    private:
        Horaire debut;
        Duree duree;
    public:
        Evt1jDur(const Date& d, const std::string& s,
                 const Horaire& h, const Duree t):
                Evt1j(d,s), // appel au constructeur de la classe de base
                debut(h),duree(t){}
        const Horaire& getHoraire() const { return debut; }
        const Duree& getDuree() const { return duree; }
        void afficher(std::ostream& f= std::cout) const {
            //f<<"***** Evt ********"<<"\n"<<"Date="<<date<<" sujet="<<sujet<<"\n";
            Evt1j::afficher(f); // rappel de la méthode de la classe de base.
            f<<"debut="<<debut<<" duree="<<duree<<"\n";
        }
    };

    class Rdv : public Evt1jDur {
    private:
        std::string personne;
        std::string lieu;
    public:
        Rdv(const Date& d, const std::string& s,
            const Horaire& h,const Duree& dur,
            const std::string& p, const std::string& l):
                Evt1jDur(d,s,h,dur),
                personne(p),lieu(l){}
        const std::string& getPersonne() const { return personne; }
        const std::string& getLieu() const { return lieu; }
        void afficher(std::ostream& f=std::cout) const {
            Evt1jDur::afficher(f); // rappel de la méthode de la classe de base.
            f<<"personne(s)="<<personne<<" lieu="<<lieu<<"\n";
        }
    };
}


#endif //CPP_EVENEMENT_H
