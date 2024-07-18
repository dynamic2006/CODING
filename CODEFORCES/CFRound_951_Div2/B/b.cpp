#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("b.in" , "r" , stdin);

    int t; cin >> t;
    while(t--){
        int x, y; cin >> x >> y;
        cout << ((x^y) & -(x^y)) << endl;
    }
}