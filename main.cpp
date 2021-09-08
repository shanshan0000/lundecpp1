#include <iostream>

int main() {
    //double& d1 = 36; // erreur, 36 n’est une lvalue
    const double& d1 = 36; /* ok pour créer une reférence const
                            un espace mémoire est créé temporairement
                            pour stocker 36. C’est c’est cet espace mémoire
                            qui est référencé.
                            */
    double d2 = 36;
    double& ref = d2;
    ref = 4; // équivalent à d2=4;
    const double d3 = 36;
    const double& d4 = 36;
    const double& d5 = d2; /* on peut créer une ref const sur une donnée
                            aussi bien constante que non constante */
    //d5 = 21;
                            /* erreur, avec une référence const, on ne peut pas modifier la donnée
                            référencée, même si cette donnée n’est pas constante */
    const double& d6 = d3;
    //double& ref2 = d6; // conversion implicite const double&->double&
    double& ref2 = const_cast<double&>(d6); // conversion explicite ok
    int i = 4;
    //double& d7 = i; // erreur, une T& doit initialisée avec une lvalue de type T
    const double& d8 = i; /* les conversions sont possibles avec les ref const.
                            Une donnée temporaire contenant le résultat de la
                            conversion de i en double est créée.
                            C’est cette donnée qui est référencée. La durée de
                            vie de la donnée temporaire est la même que celle
                            de la référence
                            */
    //d8 = 3; // erreur, on ne peut pas modifier la donnée référencée par une ref const

    return 0;
}
