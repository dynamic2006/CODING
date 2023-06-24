#include <iostream>
using namespace std;

class Double {
    public:
        double value;
        Double(double n = 0){value = n;}
        Double& GetMyself() {return *this;}
};

int main() {
    Double db;

    cout << db.value << endl;

    db.GetMyself() = 5;

    cout << db.value << endl;
}