#include <iostream>
using namespace std;

class Base{
    public:
        virtual ~Base(){
            cout << "1" << endl;
        }
};

class D1 : public Base{
    public:
        virtual ~D1() {
            cout << "2" << endl;
        }
};

class D2 : public D1{
    public:
        virtual ~D2(){
            cout << "3" << endl;
        }
};

int main() {
    Base* ptr = new D2;
    delete ptr;
}
