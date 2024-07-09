#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("a.in" , "r" , stdin);

    int t; cin >> t;
    for(int i=0; i<t; i++){
        int a1, b1, a2, b2;
        cin >> a1 >> b1;
        cin >> a2 >> b2;

        if(a1 < b1 && a2 > b2 || a1 > b1 && a2 < b2) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
}