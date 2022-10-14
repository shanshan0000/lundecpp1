#ifndef CPP_HEADER_H
#define CPP_HEADER_H

class A
{
private:
    static Handler handler;
    A(){};
    ~A(){};
    A(const A& another) = delete;
    A& operator=(const A& another) = delete;

public:
    static A& getInstance()
    {
        if(handler.instance == nullptr)
            handler.instance = new A();
        return *handler.instance;
    }

    static void libererInstance()
    {
        delete handler.instance;
        handler.instance = nullptr;
    }

    class Handler
    {
    public:
        A* instance;
        ~Handler()
        {
            delete instance;
        }
    };




    void func(){}
};


#endif //CPP_HEADER_H
