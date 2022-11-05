#include <iostream>
#include "relation.h"


int main() {
    set<unsigned int> chiffres;
    for (unsigned int i = 0; i <= 9; i++)
        chiffres.insert(i);

    set<char> voy;
    voy.insert('a');
    voy.insert('e');
    voy.insert('i');
    voy.insert('o');
    voy.insert('u');

    relation<unsigned int, char> R("chiffre-voyelle", "R", chiffres, voy);
    R.ajouter(0, 'e');
    R.ajouter(0, 'o');
    R.ajouter(1, 'u');
    R.ajouter(2, 'e');
    R.ajouter(2, 'u');
    R.ajouter(3, 'o');
    R.ajouter(3, 'i');
    R.ajouter(4, 'u');
    R.ajouter(4, 'a');
    R.ajouter(4, 'e');
    R.ajouter(5, 'i');
    R.ajouter(6, 'i');
    R.ajouter(7, 'e');
    R.ajouter(8, 'u');
    R.ajouter(8, 'i');
    R.ajouter(9, 'e');
    R.ajouter(9, 'u');
    std::cout << R;

    if (R.est_en_relation(8, 'u'))
        cout << "oui\n";
    else
        cout << "non\n";

    set<std::string> s;
    s.insert("Bao");
    s.insert("Charles");
    s.insert("Cheng");
    s.insert("Suzanne");
    s.insert("Li");
    s.insert("Pierre");
    s.insert("Xiaokang");
    endorelation<std::string> A("amour", "@", s);
    A.ajouter(std::string("Bao"), std::string("Pierre"));
    A.ajouter(std::string("Pierre"), std::string("Bao"));
    std::cout << A;
    return 0;
}
