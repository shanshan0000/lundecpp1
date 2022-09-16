#include <iostream>
#include<array>

using namespace std;

constexpr int calcul(int x) { return 2 * x + 1; }

constexpr int getNumber() { return 3; }

int main() {
    constexpr const int N = getNumber();
    int i;
    cin >> i;
    array<int, calcul(N)> tableau;
    return 0;
}