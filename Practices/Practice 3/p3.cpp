#include <iostream>
using namespace std;

class Base {
    public:
        Base(){cout << "1";}
        ~Base(){cout << "3";}
};

class Derived : public Base {
    public:
        Derived(){cout << "2";}
        ~Derived(){cout << "4";}
};

int main() {
    Base* base_ptr = new Base();
    Derived* derived_ptr = new Derived();
}