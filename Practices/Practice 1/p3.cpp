#include <iostream>
using namespace std;

class A {
    public:
        A() {cout << "C";}
        ~A() {cout << "2";}
};

class B {
    public:
        B() {cout << "S";}
        ~B() {cout << "3";}
    private:
        A a;
};

int main() {
    B b;
}