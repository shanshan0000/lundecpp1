#ifndef CPP_2021_EVENEMENT_H
#define CPP_2021_EVENEMENT_H

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
}


#endif //CPP_2021_EVENEMENT_H
