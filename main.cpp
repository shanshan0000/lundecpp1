#include <iostream>

using namespace std;

int main() {
    int i;
    cin >> i;
    int a[i];
    for (int j = 0; j < i; j ++)
        a[j] = j;
    for (int j = 0; j < i; j ++)
        cout << a[j] << endl;
    return 0;
}