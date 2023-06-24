#include <bits/stdc++.h>
using namespace std;

template<typename T>
T add(const T& a, const T& b) {
    return a + b;
}

template<typename T>
T calculate(const T& a, const T& b, function<T (const T&, const T&)> opp) {
    return opp(a,b);
}


int main(int argc, char const *argv[])
{
    //cout << calculate(2,3, [](const int& a, const int& b) { return a + b; }) << endl;
    //cout << calculate(2,3, add);
    // cout << calculate(2,3, multiply);
    // cout << calculate(2,3, divide);
    // cout << calculate(2,3, subtract);
    // cout << calculate(2.4,3.5, add);
    // cout << calculate(2.4,3.5, multiply);
    // cout << calculate(2.4,3.5, divide);
    // cout << calculate(2.4,3.5, subtract);

    return 0;
}
