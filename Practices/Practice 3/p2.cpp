#include <iostream>
using namespace std;

class A {
    public:
        ~A() {
            cout << "A is destructed!" << endl;
        }
};

int main() {
    A a;
    a.~A();
}