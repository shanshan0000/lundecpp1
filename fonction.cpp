#include "fonction.h"

int& TD1::operation(compte* tab, const std::string& c){
    while(tab->id!=c) // comparaison de chaînes
        tab++;
    return tab->solde;
}