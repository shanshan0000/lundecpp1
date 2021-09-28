#include <iostream>


class ParkingSystemOne {
public:
    int big = 0 , small = 0, medium = 0;
    ParkingSystemOne(int big, int medium, int small) {
        this->big = big ;
        this->medium = medium ;
        this->small = small ;
    }

    bool addCar(int carType) {
        if(carType == 1 && big != 0)  {big-- ; return true ;}
        else if(carType == 2 && medium != 0)  {medium-- ; return true ;}
        else if(carType == 3 && small != 0)  {small-- ; return true ;}

        return false ;
    }
};


class ParkingSystemTwo {
public:
    int big = 0 , small = 0, medium = 0;
    ParkingSystemTwo(int big, int medium, int small) {
        this->big = big ;
        this->medium = medium ;
        this->small = small ;
    }

    bool addCar(int carType) {
        if(carType == 1 && big != 0)  {big-- ; return true ;}
        else if(carType == 2 && medium != 0)  {medium-- ; return true ;}
        else if(carType == 3 && small != 0)  {small-- ; return true ;}

        return false ;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
