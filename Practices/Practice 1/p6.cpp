#include <iostream>
using namespace std;

class Test {
    int value;
    public:
        Test() {cout << "T1" << endl;}
        Test(int n) {
            value = n;
            cout << value << endl;
        }
};

int main() {
    Test a[2];
    Test b(5);
    Test* c = new Test[3];
    delete [] c;
}