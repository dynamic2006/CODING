#include <iostream>
using namespace std;

class Base{
    public:
        Base() {}
        ~Base() {}
        
        virtual void creation() {
            cout << "Base::creation()" << endl;
        }
        virtual void cleanup() {
            cout << "Base::cleanup()" << endl;
        }
};

class Derived : public Base{
    public:
        Derived(){creation();}
        ~Derived(){cleanup();}
};

class Last : public Derived{
    public:
        Last(){}
        ~Last(){cleanup();}

        void cleanup(){
            cout << "Last::cleanup()" << endl;
        }
};

int main() {
    Last L;
}