#include<array>
using namespace std;

int calcul(int x) { return 2 * x + 1; }

int getNumber() { return 3; }

int main() {
    const int N = getNumber();
    array<int, calcul(N)> tableau;
    return 0;
}