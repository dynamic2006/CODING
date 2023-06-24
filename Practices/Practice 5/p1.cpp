#include <iostream>
using namespace std;

template <typename T>
T maxtj(const T a, const T b){
    cout << "Use T max()" << endl;
    if(a>b) return a;
    return b;
}

double maxtj(double a, double b){
    cout << "Use double max()" << endl;
    if(a>b) return a;
    return b;
}

int main() {
    int a=5, b=3;
    cout << maxtj(1.20, 3.40) << endl;
    cout << maxtj(a,b) << endl;
}