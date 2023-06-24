#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;
const ll MAXN = 500;
const ll INV2 = 5*1e8 + 4;
const ll MAXSUM = 63000;

//dp[i][j] = ways to get sum of j with first i numbers
ll dp[MAXN+1][MAXSUM+1];

int main() {

    //freopen("twoset.in" , "r" , stdin);

    ll n; cin >> n;
    for(ll i=1; i<=n; i++){
        dp[i][i] = (dp[i][i] + 1) % MOD;
        for(ll j=1; j<=MAXSUM; j++){
            dp[i][j] = (dp[i][j] + dp[i-1][j]) % MOD;
            if(j>i) dp[i][j] = (dp[i][j] + dp[i-1][j-i]) % MOD;
        }
    }

    if(n % 4 != 0 && n % 4 != 3) cout << 0 << endl;
    else cout << (dp[n][(n)*(n+1)/4] * INV2) % MOD << endl;
    return 0;

}