#include <iostream>
using namespace std;

class Base{
    private:
        int base_value;
    public:
        Base(int n): base_value(n){}
        int getValue(){return base_value;}
};

class Derived : public Base{
    private:
        int derived_value;
    public:
        Derived(int n): Base(n) {derived_value = n+10;}
        int getValue(){return derived_value;}
        void output(){
            cout << "Base value is: " << Base::getValue() << endl;
            cout << "Derived value is: " << getValue() << endl; 
        }
};

int main() {
    Derived d(0);
    d.output();
}