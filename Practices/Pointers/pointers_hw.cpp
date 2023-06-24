#include <iostream>
using namespace std;

int main() {
    int v1 = 99, v2 = 1000;

    cout << "Address of v1 is: " << &v1 << endl;
    cout << "Address of v2 is: " << &v2 << endl;
    cout << "Value of v1 is: " << v1 << endl;
    cout << "Value of v2 is: " << v2 << endl;
    cout << "-------------------" << endl;

    int* p1 = &v1;
    int* p2 = &v2;

    cout << "Address of p is: " << p1 << endl;
    cout << "Address of p is: " << p2 << endl;
    cout << "Value of p is: " << *p1 << endl;
    cout << "Value of p is: " << *p2 << endl;
    cout << "-------------------" << endl;

    *p1 = *p2;

    cout << "After running *p1 = *p2..." << endl;

    cout << "Address of v1 is: " << &v1 << endl;
    cout << "Address of v2 is: " << &v2 << endl;
    cout << "Value of v1 is: " << v1 << endl;
    cout << "Value of v2 is: " << v2 << endl;
}