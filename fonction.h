#ifndef CPP_FONCTION_H
#define CPP_FONCTION_H

#include <string>
#include <iostream>

using namespace std;

class Person {
protected:
    int sex;
public:
    string name;
    void work(){
        if(sex == 0)
            cout << "996";
        else
            cout << "955";
    }
};

class Computer {
public:
    string CPU;
};

class Robot : public Person, public Computer {
};


class Student : private Person {
public:
    string id;
    void takeExam(){
        if(sex == 0)
            cout << name << "Online";
        else
            cout << "In place";
    }

    void work() {
        cout << "read a lot of books"
        << " in a ";
        Person::work();
        cout << " manner";
    }
};

class UniversityStudent : public Student {
public:
    void goForInternship() {
    }
};


class Scientist : public Person {
public:
    int IQ;
    void writePaper() {}
};








#endif //CPP_FONCTION_H
