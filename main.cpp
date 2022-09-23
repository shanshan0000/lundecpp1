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

    friend ostream& operator << (ostream &stream, const Complex &c);

    friend Complex operator-(const Complex& c, const Complex& d);
    friend Complex operator-=(Complex& c, const Complex& d);

private:
    int _real, _image;
};

Complex operator-(const Complex& c, const Complex& d)
{
    Complex temp(0, 0);
    temp._real = c._real - d._real;
    temp._image = c._image - d._image;
    return temp;
}

Complex operator-=(Complex& c, const Complex& d)
{
    c._real -= d._real;
    c._image -= d._image;
    return c;
}

ostream& operator<< (ostream &stream, const Complex &c)
{
    stream << c._real;
    stream << " + " << c._image << "i" << endl;
    return stream;
}

int main() {
    Complex d1(5, 5);
    Complex d2(3, 3);

    Complex d3(0, 0);
    Complex d4(0, 0);
    Complex d5(0, 0);
    Complex d6(0, 0);
    d3 = d1 - d2;
    d4 = d1 + d2 + d3;

//    d5 = (d1 += d2);
    d6 = (d1 -= d2);

    cout << d1 << "   " << d2;
    return 0;
}
