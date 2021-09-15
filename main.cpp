#include "fraction.h"

int main(){
    using namespace MATH;
    try{
        Fraction A(1,2); Fraction B(3,0);
    }
    catch(FractionException& e){ std::cout<<e.getInfo()<<"\n"; }

}