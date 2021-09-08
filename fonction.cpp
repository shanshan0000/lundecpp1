#include "fonction.h"

void raz(personne& p){
    p.nom=""; // afectation possible
    p.age=0;
}

void affiche_struct(const personne& p){
    cout<<"NOM : "<<p.nom<<", age="<<p.age<<"\n";
}

void affiche_tab(const personne* p, size_t n){
    for(size_t i=0; i<n; i++) { affiche_struct(*p++); }
}

void init_struct(personne& p, const std::string& n, unsigned int a){
    p.nom=n; // affectation possible
    p.age=a;
}

void copy_struct(personne& dest, const personne& source){
/* À noter que l’opérateur d’affectation est généré par le
compilateur automatiquement. Une copie champ par champ n’est donc pas nécessaire
*/
    dest=source;
}

void copy_tab(personne* dest, const personne* source, size_t n){
    for(size_t i=0; i<n; i++) dest[i]=source[i];
}