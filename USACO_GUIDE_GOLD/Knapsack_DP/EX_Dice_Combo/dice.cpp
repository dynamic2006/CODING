#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;
const ll MAXN = 1e6;

ll dp[MAXN+1];

int main() {

    dp[0] = 0;
    for(ll i=1; i<=MAXN; i++){
        if(i<=6){
            dp[i] = pow(2, i-1);
            continue;
        }
        dp[i] = (dp[i-1] + dp[i-2] + dp[i-3] + dp[i-4] + dp[i-5] + dp[i-6]) % MOD;
    }
    
    //freopen("dice.in" , "r" , stdin);

    ll n; cin >> n;
    cout << dp[n] << endl;
    return 0;

}