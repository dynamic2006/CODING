#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;
const ll MAXN = 1000;

ll dp[MAXN+1][MAXN+1];
char grid[MAXN+1][MAXN+1];

int main() {

    //freopen("paths.in" , "r" , stdin);

    ll n; cin >> n;

    for(ll i=1; i<=n; i++){
        for(ll j=1; j<=n; j++){
            cin >> grid[i][j];
        }
    }

    dp[1][1] = 1;
    for(ll i=1; i<=n; i++){
        for(ll j=1; j<=n; j++){
            if(i==1 && j==1) continue;
            if(grid[i-1][j] == '.') dp[i][j] = (dp[i][j] + dp[i-1][j]) % MOD;
            if(grid[i][j-1] == '.') dp[i][j] = (dp[i][j] + dp[i][j-1]) % MOD;
        }
    }

    if(grid[n][n] == '.') cout << dp[n][n] << endl;
    else cout << 0 << endl;
    return 0;

}