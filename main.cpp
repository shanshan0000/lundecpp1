#include <iostream>

using namespace std;

class Complex
{
public:
    Complex(int real = 0, int image = 0)
    :_real(real), _image(image){};

    ~Complex(){};

    Complex operator+(const Complex& d)
    {
        Complex temp(0, 0);
        temp._real = this->_real + d._real;
        temp._image = this->_image + d._image;
        return temp;
    }

    Complex operator+=(const Complex& d)
    {
        this->_real += d._real;
        this->_image += d._image;
        return *this;
    }

private:
    int _real, _image;
};

int main() {
    Complex d1(5, 10);
    Complex d2(7, 19);
    return 0;
}
