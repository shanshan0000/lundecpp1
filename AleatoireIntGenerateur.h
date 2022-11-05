#ifndef CPP_ALEATOIREINTGENERATEUR_H
#define CPP_ALEATOIREINTGENERATEUR_H


#include <string>
#include <cmath>
class AleatoireIntGenerateur{
    double random() const {
        static unsigned int rootA=27134;
        static unsigned int rootB=9213;
        static unsigned int rootC=17773;
        rootA= (rootA*171)%30269;
        rootB= (rootB*172)%30307;
        rootC= (rootC*170)%30323;
        double x= rootA/30269.0 + rootB/30307.0 + rootC/30323.0;
        return x-floor(x); // retourne la partie décimale (entre 0 et 1)
    }
    std::string name;
public:
    AleatoireIntGenerateur(const std::string& n=""):name(n) { }
    unsigned int GetInt(unsigned int max) const {
        double x=random()*max;
        if (x-floor(x)>0.5) return static_cast<int>(ceil(x));
        else return static_cast<int>(floor(x));
    }
};



#endif //CPP_ALEATOIREINTGENERATEUR_H
