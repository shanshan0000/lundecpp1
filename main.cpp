#include "fraction.h"

int main(){
    using namespace MATH;
    try{
        Fraction B(3,0);
    }
    catch(FractionException& e){
        std::cout<<e.getInfo()<<"\n";
    }

}