#include <iostream>
using namespace std;

class Base{
    public:
        Base() {cout << "1" << endl;}
        virtual ~Base() {cout << "4" << endl;}
};

class Derived : public Base {
    public:
        Derived() {cout << "2" << endl;}
        virtual ~Derived() {cout << "3" << endl;}
};

int main() {
    Derived d;
    Base* b = &d;
    Base* ptr = new Derived();
    delete ptr;
}