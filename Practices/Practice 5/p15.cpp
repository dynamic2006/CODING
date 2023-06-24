#include <iostream>
#include <vector>
using namespace std;

class myClass{
    public:
        myClass(int v) : value(v){
            cout << v << endl;
        }
        ~myClass(){
            cout << -value << endl;
        }

    private:
        int value;
};

int main() {
    vector<myClass*> vec;

    vec.push_back(new myClass(4));
    vec.push_back(new myClass(8));

    delete vec[0];
    delete vec[1];
}