#include <iostream>

#include <set>
#include <map>
#include <list>


class A : public std::set<int> {
public:
    void clear() {}
};




int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
