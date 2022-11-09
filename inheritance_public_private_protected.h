#ifndef CPP_INHERITANCE_PUBLIC_PRIVATE_PROTECTED_H
#define CPP_INHERITANCE_PUBLIC_PRIVATE_PROTECTED_H

#include <iostream>

class A {
protected:
    int x = 10;
public:
    A() = default;
};

class B : protected A {
public:
    void print() {
        std::cout << x;
    }
};

class C : public B {
    public:
    void print() {
        std::cout << x;
    }
};

#endif //CPP_INHERITANCE_PUBLIC_PRIVATE_PROTECTED_H
