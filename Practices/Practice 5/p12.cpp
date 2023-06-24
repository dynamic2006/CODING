#include <iostream>
#include <list>
using namespace std;

int main() {
    list<double> l;

    for(int i=0;i<5;i++){
        l.push_back(i+0.5);
    }

    list<double>::iterator it = l.end();
    cout << "end:" << *it << endl;
    cout << "end + 1:" << *++it << endl;


    // for(list<double>::iterator it = l.begin(); it != l.end(); it++){
    //     cout << *it << endl;
    //     it++;
    // }
}