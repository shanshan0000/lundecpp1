#include <iostream>


class ParkingSystem {
private:
    int big = 0 , small = 0, medium = 0;

public:
    ParkingSystem(int _big, int _medium, int _small) :
        big(_big), medium(_medium), small(_small){

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
        std::string info;
    public:
        NoPlaceException(std::string _info ) {info = _info;}
        std::string getInfo(){
            return info;
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
        else
            throw MyException();
    }
};

int main() {
    ParkingSystemTwo ps{1, 1, 1};
    try {
        ps.addCar(1);
        ps.addCar(1);
        ps.addCar(1);
    }
    catch (ParkingSystemTwo::NoPlaceException& e)
    {
        ps.big += 10;
        ps.medium += 10;
        ps.small += 10;
    }
    catch (ParkingSystemTwo::NoPlaceException& e)
    {
        ps.big += 100;
        ps.medium += 100;
        ps.small += 100;
        std::cout << e.getInfo() << std::endl;
    }



    return 0;
}
