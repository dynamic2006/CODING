#include <iostream>
using namespace std;

class ABC{
    public:
        ABC(){cout << "1";}
        ~ABC(){cout << "2";}
};

int main() {
    ABC* p = new ABC[3];
    delete [] p;
}