#include <iostream>
using namespace std;

int main() {
    int x = 5, y=10;
    const int* p = &x;

    cout << *p << endl;

    p = &y;

    cout << *p << endl;
}