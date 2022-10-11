#include <iostream>
#include <vector>

class Bar
{
public:
    void doSth(){}
};

// Simple ASSOCIATION
class Foo1
{
    void useBar(Bar* bar)
    {
        bar->doSth();
    }
};

// Simple ASSOCIATION
class Foo2A
{
    void useBar(Bar bar)
    {
        bar.doSth();
    }
};

// Simple ASSOCIATION
class Foo2B
{
    void useBar(Bar& bar)
    {
        bar.doSth();
    }
};


// Aggregation
class Foo3
{
public:
    Foo3(){}
    ~Foo3(){}
    void useBar()
    {
        bar->doSth();
    }

private:
    Bar* bar;
};


// Aggregation
class Foo4
{
public:
    Foo4(){}
    ~Foo4(){}
    void useBar(int i)
    {
        bar[i]->doSth();
    }

private:
    Bar** bar;
};

// Aggregation
class Foo5
{
public:
    Foo5(){}
    ~Foo5(){}
    void useBar(int i)
    {
        v[i]->doSth();
    }

private:
    std::vector<Bar*> v;
};

// COMPOSTION
class Foo6A
{
private:
    Bar bar;
public:
    Foo6A()
    {
        this->bar = Bar{};
    }
    void useBar()
    {
        bar.doSth();
    }
};

// COMPOSTION
class Foo6B
{
private:
    Bar bar;
public:
    Foo6B():bar{Bar()} {}
    ~Foo6B() = default;
    void useBar()
    {
        bar.doSth();
    }
};

//COMPOSTION
class Foo7
{
private:
    Bar *bar;
public:
    Foo7()
    {
        this->bar = new Bar;
    }
    ~Foo7()
    {
        delete bar;
    }
    void useBar()
    {
        bar->doSth();
    }
};

//COMPOSTION
class Foo8
{
private:
    std::vector<Bar*> v;
    int size;
public:
    Foo8()
    {
        for(int i = 0; i <= size;  i++)
            v[i] = new Bar;
    }
    ~Foo8()
    {
        for(int i = 0; i <= size;  i++)
            delete v[i];
    }
    void useBar(int i)
    {
        v[i]->doSth();
    }
};


//COMPOSTION
class Foo9
{
private:
    Bar** arr;
    int size;
public:
    Foo9()
    {
        for(int i = 0; i <= size;  i++)
            arr[i] = new Bar;
    }
    ~Foo9()
    {
        for(int i = 0; i <= size;  i++)
            delete arr[i];
    }
    void useBar(int i)
    {
        arr[i]->doSth();
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
