#include <iostream>


class ParkingSystem {
private:
    int big = 0 , small = 0, medium = 0;

public:
    ParkingSystem(int _big, int _medium, int _small) {
        big = _big ;
        medium = _medium ;
        small = _small ;
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
    class NoPlaceException {
    private:
        std::string msg;
    public:
        NoPlaceException(std::string _msg ) {msg = _msg;}
        std::string getMsg(){
            return msg;
        }
    };

    class MyException { };

    int big = 0 , small = 0, medium = 0;
    ParkingSystemTwo(int big, int medium, int small) {
        this->big = big ;
        this->medium = medium ;
        this->small = small ;
    }

    void addCar(int carType) {
        if(carType == 1 && big > 0)  {big-- ; std::cout << "Parking Big success";}
        else if(carType == 1 && big == 0)
            throw NoPlaceException("No Parking lot for Big");
        else if(carType == 2 && medium > 0)  {medium-- ; std::cout << "Parking Medium success";}
        else if(carType == 2 && medium == 0)
            throw NoPlaceException("No Parking lot for medium");
        else if(carType == 3 && small > 0)  {small-- ; std::cout << "Parking Samll success";}
        else if(carType == 3 && small == 0)
            throw NoPlaceException("No Parking lot for small");
        throw MyException();
    }
};

int main() {
    ParkingSystemTwo ps{-1, -2, -3};
    try {
        ps.addCar(1);
        ps.addCar(1);
        ps.addCar(2);
        ps.addCar(2);
        ps.addCar(2);
    }
    catch (ParkingSystemTwo::MyException& e)
    {
        ps.big += 10;
        ps.medium += 10;
        ps.small += 10;
    }
//    catch (ParkingSystemTwo::NoPlaceException& e)
//    {
//        std::cout << e.getMsg() << std::endl;
//    }

    ps.addCar(1);
    return 0;
}
