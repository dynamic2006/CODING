#include <iostream>
using namespace std;

class Double{
    public:
        Double():value(0){cout << "1";}
        Double(double num):value(num){cout << "4";}
        double getValue(){return value;}
        ~Double() {cout << "9";}
    private:
        double value;
};

int main() {
    Double a,b=2,c=b;
    a=b;
    cout << a.getValue() << b.getValue() << c.getValue();
}