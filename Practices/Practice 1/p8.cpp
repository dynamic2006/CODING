#include <iostream>
using namespace std;

class Double{
    public:
        double value;
        Double() {};
        Double(double n):value(n) {};
        Double(const Double &db) {value = db.value + 1;}
};

Double Output(Double* db){
    cout << db->value;
    db->value = db->value*3;
    return *db;
}

int main() {
    Double a(1);
    Double b = a;
    Double c = Output(&b);

    cout << c.value;

    Double d; d = a;

    cout << d.value;
}