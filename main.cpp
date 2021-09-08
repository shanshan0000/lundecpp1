#include <iostream>

void essai_alloc(){
    int* pt_int;
    double* pt_double;
    pt_int=(int*)malloc(sizeof(int));
    pt_double=(double*)malloc(sizeof(double)*100);
    free(pt_int);
    free(pt_double);
}

int main() {
    essai_alloc();
    return 0;
}
