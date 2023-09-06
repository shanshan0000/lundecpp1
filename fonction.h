#ifndef CPP_FONCTION_H
#define CPP_FONCTION_H

#include <iostream>
#include <string>

using namespace std;

struct personne {
    std::string nom;
    unsigned int age;
};

void raz(personne& p);
void affiche_struct(const personne& p);
void affiche_tab(const personne* p, size_t n);
void init_struct(personne& p, const std::string& n, unsigned int a);
void copy_struct(personne& dest, const personne& source);
void copy_struct_2(personne&, const personne&);
void copy_tab(personne* dest, const personne* source, size_t n);


#endif //CPP_FONCTION_H
