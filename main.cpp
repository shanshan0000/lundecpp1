#include <iostream>

#include "container.h"
#include "vector.h"
#include "stack.h"
#include "my_algorithm.h"

using namespace std;

void question_1(){
    // Iteration sur les elements de Vector
    Vector<int> vect1(10, 0);

    for(Vector<int>::const_iterator it = vect1.cbegin() ; it != vect1.cend() ; it++) {
        cout << *it << endl;
    }

    // Iteration sur les elements de Stack - Adaptateur d'objets
    AO::StackP<int> stk;
    stk.push(1);
    stk.push(2);
    stk.push(3);

    for(AO::StackP<int>::iterator it = stk.begin() ; it != stk.end() ; it++) {
        cout << *it << endl;
    }

    // Iteration sur les elements de Stack - Adaptateur de classes
    AC::StackP<int> stkc;
    stkc.push(4);
    stkc.push(5);
    stkc.push(6);

    for(AC::StackP<int>::iterator it = stkc.begin() ; it != stkc.end() ; it++) {
        cout << *it << endl;
    }
}


bool inf(int a , int b) { return a<b; }
bool sup(int a , int b) { return a>b; }
class comparateur {
public:
    enum ordre { croissant, decroissant };
private :
    ordre d;
public:
    comparateur(ordre o=croissant):d(o){}
    bool operator()(int a, int b) { if (d==croissant) return a<b; else return a>b; }
};

void question_2_et_3(){
    using namespace TD;
    using namespace AO;
    try {
        Vector<int> tab(10,1);
        tab[0]=1;
        tab[4]=23;
        tab[6]=-10;
        for(Vector<int>::iterator it=tab.begin(); it!=tab.end(); ++it) std::cout<<*it<< " ";
        std::cout<<"\n";
        Vector<int> tab2=tab;
        for(Vector<int>::iterator it=tab2.begin(); it!=tab2.end(); ++it) std::cout<<*it<< " ";
        std::cout<<"\n";
        tab2[4]=5;
        tab2[5]=6;
        tab2.push_back(58);
        tab2.push_back(60);
        for(Vector<int>::iterator it=tab2.begin(); it!=tab2.end(); ++it) std::cout<<*it<< " ";
        std::cout<<"\n";
        StackP<int> p2;
        p2.push(14);
        p2.push(15);
        p2.push(14);
        p2.push(15);
        for(StackP<int>::iterator it=p2.begin(); it!=p2.end(); ++it) std::cout<<*it<<" ";
        std::cout<<"\n";
        StackP<int,Vector<int> > p3;
        p3.push(14);
        p3.push(15);
        p3.push(14);
        p3.push(15);
        for(StackP<int,Vector<int> >::iterator it=p3.begin(); it!=p3.end(); ++it) std::cout<<*it<<" ";
        std::cout<<"\n";
        auto it=element_minimum(tab.begin(),tab.end());
        auto ita=element_minimum(tab.begin(),tab.end(),inf);
        auto itb=element_minimum(tab.begin(),tab.end(),comparateur(comparateur::decroissant));
        auto itc=element_minimum(tab.begin(),tab.end(),[](int a, int b){ return a>b; });
        std::cout<<"le min="<<*it<<std::endl;
        std::cout<<"le min="<<*ita<<std::endl;
        std::cout<<"le min="<<*itb<<std::endl;
    }
    catch(std::exception& e){
        std::cout<<"erreur\n";
        std::cout<<e.what();
    }
}


int main()
{
    question_2_et_3();
    return 0;
}