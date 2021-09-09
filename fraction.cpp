#include <iostream>
#include "fraction.h"
using namespace std;
using namespace MATH;

// à ajouter en tant méthode privée de la classe Fraction
void MATH::Fraction::simplification(){
// si le numerateur est 0, le denominateur prend la valeur 1
    if (numerateur==0) { denominateur=1; return; }
/* un denominateur ne devrait pas être 0;
si c’est le cas, on sort de la méthode */
    if (denominateur==0) return;
/* utilisation de l’algorithme d’Euclide pour trouver le Plus Grand Commun
Denominateur (PGCD) entre le numerateur et le denominateur */
    int a=numerateur, b=denominateur;
// on ne travaille qu’avec des valeurs positives...
    if (a<0) a=-a; if (b<0) b=-b;
    while(a!=b){ if (a>b) a=a-b; else b=b-a; }
// on divise le numerateur et le denominateur par le PGCD=a
    numerateur/=a; denominateur/=a;
// si le denominateur est négatif, on fait passer le signe - au denominateur
    if (denominateur<0) { denominateur=-denominateur; numerateur=-numerateur; }
}

Fraction* myFunction(){
    Fraction fx(7,8);
    Fraction* pfy=new Fraction(2,3);
    return pfy;
}

int main(){
    Fraction f1(3,4);
    Fraction f2(1,6);
    Fraction* pf3=new Fraction(1,2);
    cout<<"ouverture d’un bloc\n";
    Fraction* pf6;
    {
        Fraction f4(3,8);
        Fraction f5(4,6);
        pf6=new Fraction(1,3);
    }
    cout<<"fin d’un bloc\n";
    cout<<"debut d’une fonction\n";
    Fraction* pf7=myFunction();
    cout<<"fin d’une fonction\n";
    cout<<"desallocations controlee par l’utilisateur :\n";
    delete pf6;
    delete pf7;
    return 0;
}


