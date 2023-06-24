#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;
const ll MAXX = 1e6;

ll dp[MAXX+1];

int main() {

    //freopen("coin.in" , "r" , stdin);

    ll n, x; cin >> n >> x;
    vector<ll> values(n);
    for(ll i=0; i<n; i++){
        cin >> values[i];
    }
    sort(values.begin() , values.end());

    dp[0] = 1;
    for(ll i=1; i<=x; i++){
        for(ll j=0; j<n; j++){
            if(values[j] > i) break;
            dp[i] = (dp[i] + dp[i - values[j]]) % MOD;
        }
    }

    cout << dp[x] << endl;
    return 0;

}