#ifndef CPP_FONCTION_H
#define CPP_FONCTION_H

#include <iostream>

using namespace std;

struct personne {
    char nom[30];
    unsigned int age;
};
void raz(personne& p);
void raz(personne* p);
void affiche_struct(const personne& p);
void affiche_struct(const personne*);
void affiche_tab(const personne* p, size_t n);
void affiche_tab_2(const personne*, size_t);
void affiche_tab_3(const personne*, size_t);
void init_struct(personne& p, const char* n, unsigned int a);
void copy_struct(personne& dest, const personne& source);
void copy_tab(personne* dest, const personne* source, size_t n);


#endif //CPP_FONCTION_H
