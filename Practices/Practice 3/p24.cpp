#include <iostream>
using namespace std;

class Base{
    public:
        virtual ~Base(){
            cout << "32";
        }
};

class Derived : public Base{
    public:
        ~Derived(){
            cout << "CS";
        }
};

int main(){
    Base* ptr = new Derived;
    delete ptr;
    cout << endl;
}