#include <iostream>

void inverse(int* a, int* b){

}

void inverse(int& a, int& b){

}

/*
 *  void inverse(int a, int b) {
// ne fonctionne pas, a et b sont des variables locales
    auto tmp = a; a = b; b = tmp;
}
 */


int main() {
    int x = 7, y = 9;
    inverse(&x, &y);
    inverse(x, y);

    return 0;
}
