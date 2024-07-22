#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;
const ll MAXNUM = 1e6 + 1;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("dice.in", "r", stdin);

    ll n; cin >> n;
    vector<ll> dp(MAXNUM,0);
    dp[0] = 1;
    for(int i=1; i<=6; i++){
        for(int j=i-1; j>=0; j--) dp[i] += dp[j];
    }

    for(int i=7; i<=n; i++){
        for(int j=i-1; j>= i-6; j--) dp[i] = (dp[i] + dp[j]) % MOD;
    }

    cout << dp[n] << endl;
}