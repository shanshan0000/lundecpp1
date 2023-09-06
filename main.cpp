#include "fonction.h"

int main() {
    personne p1;
    affiche_struct(p1);
    raz(p1);
    affiche_struct(p1);
    personne p2={"Cooper", 28 };
    affiche_struct(p2);
    init_struct(p2, "Wolowitz", 27);
    affiche_struct(p2);
    copy_struct(p1,p2);
    affiche_struct(p2);
    personne tab1[3]={ "Cooper", 28, "Wolowitz", 27, "Hofstadter", 30 };

    affiche_tab(tab1, 3);
    affiche_tab_2(tab1, 3);
    affiche_tab_3(tab1, 3);

    personne tab2[3];
    copy_tab(tab2,tab1,3);
    affiche_tab(tab2,3);

    return 0;
}
