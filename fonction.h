#ifndef CPP_2021_FONCTION_H
#define CPP_2021_FONCTION_H

#include<string>
#include<iostream>

using namespace std;

namespace TD1 {
    struct compte {
        string id;
        int solde;
    };

    int& operation(compte* tab, const std::string& c);
}



#endif //CPP_2021_FONCTION_H
