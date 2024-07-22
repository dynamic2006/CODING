#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll MAXNUM = 5000;
const ll MOD = 998244353;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("subsetSum.in", "r", stdin);

    ll q, k; cin >> q >> k;
    vector<ll> dp(MAXNUM+1, 0); dp[0] = 1;
    for(ll query=0; query<q; query++){
        char c; ll num; cin >> c >> num;
        if(c == '-'){
            for(ll i=num; i<=MAXNUM; i++){
                dp[i] += (MOD - dp[i-num]);
                dp[i] %= MOD;
            }
        }
        else{
            for(ll i=MAXNUM; i>=num; i--){
                dp[i] += dp[i-num];
                dp[i] %= MOD;
            }
        }
        // cout << i << ":" << dp[i] << " ";
        // cout << endl;
        cout << dp[k] << endl;
    }

}