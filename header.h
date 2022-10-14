#ifndef CPP_HEADER_H
#define CPP_HEADER_H

class A
{
private:
    A(){};
    ~A(){};
    A(const A& another) = delete;
    A& operator=(const A& another) = delete;

public:
    static A& getInstance()
    {
        static A instance;
        return instance;
    }

    void func(){}
};


#endif //CPP_HEADER_H
