#include <iostream>
using namespace std;

int main() {
    int* p;
    p = new int;
    cout << "*p= " << *p << endl;

    int* q = p;

    cout << "p= " << p << endl;
    cout << "a= " << q << endl;

    delete p;

    *q = 100;

    cout << "*p= " << *p << endl;

    cout << "p= " << p << endl;
    cout << "q= " << q << endl;
}