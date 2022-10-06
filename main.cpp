#include <iostream>

using namespace std;

class IntList
{
private:
    int m_list[10]{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }; // give this class some initial state for this example

public:
    int& operator[] (int index);
    int operator[] (int index) const; // could also return const int& if returning a non-fundamental type
};

int& IntList::operator[] (int index) // for non-const objects: can be used for assignment
{
    cout << "AAA" << endl;
    return m_list[index];
}

int IntList::operator[] (int index) const // for const objects: can only be used for access
{
    cout << "BBB" << endl;
    return m_list[index];
}

int main()
{
    IntList a{};
    a[2] = 3; // okay: calls non-const version of operator[]
    std::cout << a[2] << '\n';

    const IntList b{};
    std::cout << b[2] << '\n';

    return 0;
}