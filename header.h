#ifndef CPP_HEADER_H
#define CPP_HEADER_H

class A
{
private:
    static A* instance;
    A(){};
    ~A(){};
    A(const A& another) = delete;
    A& operator=(const A& another) = delete;

public:
    static A& getInstance()
    {
        if(instance == nullptr)
            instance = new A();
        return *instance;
    }

    static void libererInstance()
    {
        delete instance;
        instance = nullptr;
    }

    void func(){}
};


#endif //CPP_HEADER_H
