#include <iostream>
#include <string>
using namespace std;

class Other
{
    int value;
    public:
        Other(int n): value(n) {cout << "O" << value;}
        ~Other() {cout << "~O" << value;}
};

class Base
{
    public:
        Base(int i):o(i) {cout << "B"; value = i;}
        virtual ~Base() {cout << "~B";}
        virtual void output_value() {cout << value;}

    private:
        int value;
        Other o;
};

class Derived : public Base
{
    public:
        Derived(int i) : Base(i+1), value(i), o(i) {cout << "D";}
        ~Derived() {cout << "~D";}
        virtual void output_value() {cout << value;}
    
    private:
    int value;
    Other o;
};

void processAll(Base* bp)
{
    bp->output_value();
    delete bp;
}

int main()
{
    processAll(new Base(2)); cout << " ";
    processAll(new Derived(3)); cout << endl;
}