#include <iostream>

using namespace std;

void exerciceA(){
    const double PI=3.14159; // doit être initialisée
    cout<<"donnez le rayon entier d’un cercle:";
    int r;
    cin>>r;
    auto p=2*PI*r;
    auto s=PI*r*r;
    cout<<"le cercle de rayon "<<r<<" ";
    cout<<"a un perimetre de "<<p
        <<" et une surface de "<<s<<"\n";
}


int main() {
    exerciceA();
    return 0;
}
