#include <iostream>

class MyVector{
public:
    int* arr;
    MyVector()
    {
        arr = new int[5];
        for(int i = 0; i <= 4; i ++)
            arr[i] = i;
    }
    class iterator{
    public:
        int* current;
        iterator(int* c) : current(c){}
        bool operator!=(iterator another){
            return current != another.current;
        }

        iterator& operator++(){
            current ++;
            return *this;
        }

        iterator operator++(int){
            int* tmp = current;
            current ++;
            return iterator(tmp);
        }

        const int operator*() const{
            return *current;
        }

    };

    const MyVector::iterator begin() const {
        return MyVector::iterator(this->arr);
    }

    iterator end() const {
        return iterator(this->arr + 5);
    }
};


class MyAgenda
{
public:
    MyVector tab;
    MyAgenda(){
        tab = MyVector();
    }
    class iterator1 : public MyVector::iterator{
    public:
        // 这儿的星号可以不重载
        int operator*(){
            return MyVector::iterator::operator*();
        }

        iterator1(const MyVector::iterator& it): MyVector::iterator(it){};
    };

    iterator1 begin() const{
        return iterator1(tab.begin());
    }

    iterator1 end() const{
        return iterator1(tab.end());
    }

    class iterator2 : public MyVector::iterator{
    public:
        iterator2(int* cc) : MyVector::iterator(cc){}
    };

    iterator2 begin2() const{
        return iterator2(tab.begin().current);
    }

    iterator2 end2() const{
        return iterator2(tab.end().current);
    }
};

class MyStack : private MyVector
{
public:
    using MyVector::iterator;
    using MyVector::begin;
    using MyVector::end;
};


int main() {
    using namespace std;

    MyAgenda a;
    for(MyAgenda::iterator1 it = a.begin(); it != a.end(); ++it )
        std::cout << *it << std::endl;

    for(MyAgenda::iterator2 it = a.begin2(); it != a.end2(); ++it )
        std::cout << *it << std::endl;

    MyStack s;
    for(auto it = s.begin(); it != s.end(); ++it )
        std::cout << *it << std::endl;

    return 0;
}
