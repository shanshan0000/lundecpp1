#ifndef CPP_HEADER_H
#define CPP_HEADER_H

class A
{
private:
    class Handler
    {
    public:
        A* instance;
        Handler():instance(nullptr){}
        ~Handler()
        {
            delete instance;
            instance = nullptr;
        }
    };
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






    void func(){}
};


#endif //CPP_HEADER_H
