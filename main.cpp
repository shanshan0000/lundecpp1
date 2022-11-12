#in#include <iostream>

using namespace std;

class A {
private:
    int x;
public:
    class B {
    private:
        int x;
    public:
        void f() {
            x=9;
            cout << x << endl;
        }
    };

    void f() {
        x=99;
        cout << x << endl;
    }
};

int main()
{
    A a;
    a.f();
    A::B b;
    b.f();
    return 0;
}