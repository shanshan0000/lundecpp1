#include <iostream>

class Bar
{
public:
    void doSth(){}
};

// Simple ASSOCIATION
class Foo
{
    void useBar(Bar* _bar)
    {
        _bar->doSth();
    }
};

// Simple ASSOCIATION
class Foo1
{
    void useBar(Bar _bar)
    {
        _bar.doSth();
    }
};


// Aggregation
class Foo2
{
public:
    Foo2(){}
    ~Foo2(){}
    void useBar()
    {
        bar->doSth();
    }

private:
    Bar* bar;
};


//COMPOSTION
class Foo3
{
private:
    Bar bar;
public:
    Foo3()
    {
        this->bar = Bar{};
    }
    void useBar()
    {
        bar.doSth();
    }
};

//COMPOSTION
class Foo4
{
private:
    Bar *bar;
public:
    Foo4()
    {
        this->bar = new Bar;
    }
    ~Foo4()
    {
        delete bar;
    }
    void useBar()
    {
        bar->doSth();
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
