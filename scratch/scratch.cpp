#include <bits/stdc++.h>
using namespace std;

int add(const int a, const int b){
    return a+b;
}

int multiply(const int a , const int b){
    return a*b;
}

int main(int argc, char const *argv[])
{
    int(* pFunc[2])(const int, const int);
    pFunc[0] = add;
    pFunc[1] = multiply; 
    for (int i = 0; i< 2; i++) {
        cout << pFunc[i](2, 3) << endl;
    }
    return 0;
}
