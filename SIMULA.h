#ifndef CPP_SIMULA_H
#define CPP_SIMULA_H

#include "RandomIntGenerator.h"
#include "AleatoireIntGenerateur.h"

class Simula3000 {
    RandomGenerator *gen;
public:
    Simula3000() : gen(nullptr) {}

    void set_generateur(RandomGenerator &G) { gen = &G; }
};





#endif //CPP_SIMULA_H
