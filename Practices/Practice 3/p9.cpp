#include <iostream>
using namespace std;

class A{
    public:
        virtual void output(){cout <<"A" << endl;}
};

class B : public A{
    public:
        void output() {cout << "B" << endl;}
};

int main() {
    A* a = new A(); a->output();
    A* b = new B(); b->output();
    delete a,b;
}