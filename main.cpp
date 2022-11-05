#include <iostream>
#include "distributeur.h"

int main() {
    //Distributeur<int> d; // provoque une erreur à la compilation

    std::cout << "ESSAI PILE :";
    Pile<int> p;
    p.put(4);
    p.put(9);
    p.put(2);
    p.put(7);
    std::cout << p.item() << " ";
    p.remove();
    std::cout << p.item() << "\n";
    std::cout << "size=" << p.size() << "\n";

    std::cout << "ESSAI FILE :";
    File<int> f;
    f.put(4);
    f.put(9);
    f.put(2);
    f.put(7);
    std::cout << f.item() << " ";
    f.remove();
    std::cout << f.item() << "\n";

    std::cout << "ESSAI TAS :";
    Tas<int> t;
    t.put(4);
    t.put(9);
    t.put(2);
    t.put(7);
    t.put(6);
    std::cout << t.item() << " ";
    t.remove();
    std::cout << t.item() << "\n";
    return 0;
}
