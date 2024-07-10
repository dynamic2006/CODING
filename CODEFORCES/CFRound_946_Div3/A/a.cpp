#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("a.in" , "r" , stdin);

    int t; cin >> t;
    while(t--){
        int x, y; cin >> x >> y;
        int screens = 0;
        if(y%2 == 0){
            screens = y/2;
            x -= min(7*screens, x);
        }
        else{
            screens = y/2 + 1;
            x -= min(7*screens + 4, x);
        }
        screens += (x+14)/15;
        cout << screens << endl;
    }
}