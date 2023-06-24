#include <iostream>
using namespace std;

class Other{
    public:
        Other(int n){cout << "Other::" << n+10 << endl;}
        ~Other(){cout << "~Other::-15" << endl;}
};

class Base{
    int value;
    public:
        Base(int n):value(n){cout << "Base::" << n << endl;}
        ~Base(){cout << "~Base::" << -value << endl;}
};

class D1 : public Base{
    Other o;
    public:
        D1(int n): Base(n), o(n) {cout << "D1::" << n+5 << endl;}
        ~D1(){cout << "~D1::-10" << endl;}
};

int main() {
    D1 d(5);
}