#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;
const ll MAXSIZE = 1e6;

ll dp[MAXSIZE+1];

int main() {

    //freopen("coin.in" , "r" , stdin);

    ll n, x; cin >> n >> x;
    vector<ll> coins(n);
    for(int i=0; i<n; i++) cin >> coins[i];

    for(auto c : coins){
        dp[c] = (dp[c] + 1) % MOD;
        for(int i=c+1; i<=MAXSIZE; i++){
            if(dp[i-c] != 0) dp[i] = (dp[i] + dp[i-c]) % MOD;
        }
    }

    cout << dp[x] << endl;
    return 0;

}