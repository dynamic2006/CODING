#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll MAXNUM = 1e6 + 1;
const ll MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("coin.in", "r", stdin);

    ll n, x; cin >> n >> x;
    vector<ll> coins(n);
    for(int i=0; i<n; i++) cin >> coins[i];

    vector<ll> dp(MAXNUM, 0); dp[0] = 1;
    for(int i=1; i<=MAXNUM; i++){
        for(auto &c : coins){
            if(c <= i) dp[i] = (dp[i] + dp[i-c]) % MOD;
        }
    }
    cout << dp[x] << endl;

}