#include <iostream>
#include <algorithm>
using namespace std;

template <typename T>
class myClass{
    public:
        myClass() {}

        void setValue(const T& v) {value = v;}
        T getValue() const {return value;}

    private:
        T value;
};

template <typename T>
bool operator<(const myClass<T> &a, const myClass<T>& b){
    return a.getValue() < b.getValue();
}

int main() {
    myClass<int> mc[20];

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