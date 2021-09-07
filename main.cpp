#include <iostream>

int main() {
    double* pt0=0; // ok, mais en C++11, il est préférable d’utiliser nullptr au lieu des littérales 0 ou NULL
// double* pt0=nullptr; // beaucoup mieux !
//double* pt1=4096; // erreur, pas de conversion implicite de int vers double*
    double* pt2=(double*)4096; // ok, conversion explicite de type C autorisée; dangereux à utiliser (est ce que cette adresse est valide ? y a t-il une valeur de type double à cette adresse) ;
//double* pt2=reinterpret_cast<double*>(4096); // est la façon de faire en C++
    void* pt3=pt1; // ok, conversion implicite de double* en void* autorisée
    pt1=pt3; // erreur, conversion implicite de void* en double* interdite
    pt1=static_cast<double*>(pt3); // ok, conversion explicite autorisée
    double d1=36; // ok
    const double d2=36; // ok
    double* pt4=&d1; // ok
    const double* pt5=&d1; // ok, conversion implicite de double* vers const double*
    *pt4=2.1; // ok, modification de la valeur pointée possible
    *pt5=2.1; // erreur, pas de modification de la valeur pointée possible à partir d’ un pointeur const
    pt4=&d2; // erreur, pas de conversion implicite posssible de const double* vers
    double* pt5=&d2; // ok
    double* const pt6=&d1; // ok
    pt6=&d1; // erreur, on ne peut pas changer la valeur d’un pointeur constant
    *pt6=2.78; // ok, pt6 est un pointeur constant, mais pas un pointeur const
    double* const pt6b=&d2; // erreur, pas de conversion de const double* vers double* const
    const double* const pt7=&d1; // ok
    pt7=&d1; // erreur, on ne peut pas changer la valeur d’un pointeur constant
    *pt7=2.78; // erreur, pas de modification possible de la valeur pointée à partir d’ un pointeur const
    double const* pt8=&d1; // ok, attention équivalent à const double* pt8=&d1;
    pt8=&d2; // ok
    pt8=&d1; // ok, conversion implicite de double* vers const double*
    *pt8=3.14; // erreur, pas de modification possible de la valeur pointée à partir d’ un pointeur const
    return 0;
}
