#ifndef CPP_RANDOMINTGENERATOR_H
#define CPP_RANDOMINTGENERATOR_H

#include "AleatoireIntGenerateur.h"


class RandomGenerator {
protected:
    unsigned int max;
public:
    unsigned int GetMax() const { return max; }
    RandomGenerator(int m):max(m){}
    // renvoie un nombre aléatoire de {0,...,GetMax()}
    virtual unsigned int GetNumber() const=0;
};

namespace OBJECT_ADAPTER{
    class RandomIntGenerator : public RandomGenerator{
    private :
        AleatoireIntGenerateur G;
    public:
        RandomIntGenerator(unsigned int m):RandomGenerator(m),G("Simula3000"){}
        unsigned int GetNumber() const { return G.GetInt(max); }
    };
}
namespace CLASS_ADAPTER{
    class RandomIntGenerator : public RandomGenerator, private
    AleatoireIntGenerateur{
    public:
        RandomIntGenerator(unsigned int m):RandomGenerator(m),AleatoireIntGenerateur("Simula3000"){}
        unsigned int GetNumber() const { return GetInt(max); }
    };
}





#endif //CPP_RANDOMINTGENERATOR_H
