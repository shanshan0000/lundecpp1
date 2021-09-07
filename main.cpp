#include <iostream>

using namespace std;

int main() {
    double x=3.14; // c’est une initialisation
/* alternatives possibles */
// double x(3.14);
// double x{3.14};
// double x={3.14}; // plus rare
// auto x=3.14;
// auto x(3.14);
// auto x{3.14};
    cout<<"x="<<x<<"\n";
    double y;
    cout<<"y="<<y<<"\n";
    y=3.14; // c’est une affectation
    cout<<"y="<<y<<"\n";

    return 0;
}
