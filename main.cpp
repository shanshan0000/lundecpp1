#include <iostream>

int main() {
    std::cout.operator<<(10).operator<<("Hello world").operator<<('c').operator<<(std::endl);
    std::cout.operator<<("10").operator<<("Hello world").operator<<('c');
    return 0;
}
