#include <iostream>
using namespace std;

class A{
    public:
        virtual void output(int n){
            cout << "A" << n << endl;
        }
};

class B : public A{
    public:
        virtual void output(int n){
            A::output(1000);
            cout << "B" << n << endl;
        }
};

int main() {
    B b;
    b.output(5);
}