#include <iostream>
#include <algorithm>
using namespace std;

class myClass{
    public:
        myClass() {}

        void setValue(const int& v) {value = v;}
        int getValue() const {return value;}

    private:
        int value;
};

bool operator<(const myClass& a, const myClass& b){
    return a.getValue() < b.getValue();
}

int main() {
    myClass mc[20];

    for(int i=0;i<10;i++){
        mc[i].setValue(10-i);
    }

    cout << "Before Sorting:" << endl;

    for(int i=0;i<10;i++){
        cout << mc[i].getValue() << endl;
    }

    sort(mc, mc+10);

    cout << "After Sorting:" << endl;

    for(int i=0;i<10;i++){
        cout << mc[i].getValue() << endl;
    }
}