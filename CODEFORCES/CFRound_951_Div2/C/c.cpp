#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("c.in" , "r" , stdin);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<ll> multipliers(n);
        for(int i=0; i<n; i++) cin >> multipliers[i];

        ll lcm = 1;
        for(int i=0; i<n; i++){
            lcm = lcm*multipliers[i] / __gcd(lcm, multipliers[i]);
        }
        
        ll total = 0;
        vector<ll> coins(n);
        for(int i=0; i<n; i++){
            coins[i] = lcm/multipliers[i];
            total += coins[i];
        }

        if(total >= lcm) cout << -1;
        else for(auto x : coins) cout << x << " ";
        cout << endl;

    }
}