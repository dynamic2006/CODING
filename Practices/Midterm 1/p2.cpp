#include <iostream>
using namespace std;

class Complex{
    private:
        double r,i;
    public:
        Complex(): r(0), i(0){}
        Complex(int c_r, int c_i): r(c_r), i(c_i) {}

        void output(){
            cout << r <<" + " << i << "i" << endl;
        }
};

int main(){
    Complex a, b;
    
    a = Complex(1,2);
    a.output();

    b = Complex(6,7);
    b.output();

    a = b;

    a.output();
    b.output();
}