#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("b.in" , "r" , stdin);

    int t; cin >> t;
    while(t--){
        ll x, y, ops; cin >> x >> y >> ops;
        x++; ops--;
        do{
            int r = x%y;
            if(r == 0) x /= y;
            else{
                x += min(ops, y-r);
                ops -= min(ops, y-r);
            }
        }while(x>1 && ops>0);

        while(x%y == 0) x /= y;

        if(ops>0){
            int block = y-1;
            ops = ops%block;
            x += ops;
        }
        cout << x << endl;
    }
    
}