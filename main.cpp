#include <iostream>

void essai_alloc(){
    int* pt_int=nullptr;
    double* pt_double=nullptr;
    pt_int=new int;
    pt_double=new double[100];
    delete pt_int;
    delete[] pt_double;
}

int main() {
    essai_alloc();
    return 0;
}
