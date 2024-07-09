#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("a.in" , "r" , stdin);

    int t; cin >> t;
    for(int i=0; i<t; i++){
        int a, b, c; cin >> a >> b >> c;
        if(a >= b && b >= c || a <= b && b <= c) cout << abs(a-c) << endl;
        else if (b >= a && a >= c || b <= a && a <= c) cout << abs(b-c) << endl;
        else cout << abs(a-b) << endl;
    }
}