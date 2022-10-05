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
        Evt1j(const Date& d, const std::string& s):date(d),sujet(s)
        {
            std::cout << "construction d'un objet de la classe Evt1j" << std::endl;
        }
        ~Evt1j()
        {
            std::cout << "destruction d'un objet de la classe Evt1j" << std::endl;
        }
        const std::string& getDescription() const { return sujet; }
        const Date& getDate() const { return date; }
        virtual void afficher(std::ostream& f= std::cout) const;
    };

    class Evt1jDur : public Evt1j {
    private:
        Horaire debut;
        Duree duree;
    public:
        Evt1jDur(const Date& d, const std::string& s,
                 const Horaire& h, const Duree t):
                Evt1j(d,s), // appel au constructeur de la classe de base
                debut(h),duree(t)
        {
            std::cout << "construction d'un objet de la classe Evt1jDur" << std::endl;
        }
        ~Evt1jDur()
        {
            std::cout << "destruction d'un objet de la classe Evt1jDur" << std::endl;
        }
        const Horaire& getHoraire() const { return debut; }
        const Duree& getDuree() const { return duree; }
        void afficher(std::ostream& f= std::cout) const;

    };

    class Rdv : public Evt1jDur {
        std::string personne;
        std::string lieu;
    public:
        Rdv(const Date& d, const std::string& s,
            const Horaire& h,const Duree& dur,
            const std::string& p, const std::string& l):
                Evt1jDur(d,s,h,dur),
                personne(p),lieu(l)
        {
            std::cout << "construction d'un objet de la classe Rdv" << std::endl;
        }
        ~Rdv()
        {
            std::cout << "destruction d'un objet de la classe Rdv" << std::endl;
        }

        Rdv& operator=(const Rdv& r){
            Evt1jDur* x=this;
            *x=r; // recopie de la partie Evt1jDur
            personne=r.personne;
            lieu=r.lieu;
            return *this;
        }
        // Or:
//        Rdv& operator=(const Rdv& r){
//            this->Evt1jDur::operator=(r);
//            personne=r.personne;
//            lieu=r.lieu;
//            return *this;
//        }



        Rdv(const Rdv& r):Evt1jDur(r),personne(r.personne),lieu(r.lieu){}
        // Or:
//        Rdv(const Rdv& r):
//                Evt1jDur(r.getDate(), r.getDescription(),r.getHoraire(),r.getDuree()),
//                personne(r.personne),lieu(r.lieu){}


        const std::string& getPersonne() const { return personne; }
        const std::string& getLieu() const { return lieu; }
        void afficher(std::ostream& f= std::cout) const;

    };
}

std::ostream& operator<<(std::ostream&, const TIME::Evt1j&);

#endif //CPP_EVENEMENT_H
