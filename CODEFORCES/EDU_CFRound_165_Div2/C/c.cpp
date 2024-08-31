#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll MAXNUM = 1e18;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("c.in", "r", stdin);

    int t; cin >> t;
    while(t--){
        ll n, k; cin >> n >> k;
        vector<ll> a(n+1); a[0] = 0;
        for(int i=1; i<=n; i++) cin >> a[i];

        vector<vector<ll>> dp(k+1, vector<ll>(n+1, MAXNUM)); dp[0][0] = 0;
        for(ll j=1; j<=n; j++) dp[0][j] = dp[0][j-1] + a[j];
        for(ll i=1; i<=k; i++) dp[i][0] = 0;

        for(ll i=0; i<=k; i++){
            for(ll j=0; j<=n; j++){
                //push dp
                ll minNum = MAXNUM;
                for(ll ops=0; ops<=k; ops++){
                    if(i+ops > k || j+ops+1 > n) break;
                    minNum = min(minNum, a[j+ops+1]);
                    dp[i+ops][j+ops+1] = min(dp[i+ops][j+ops+1], dp[i][j] + minNum*(ops+1));
                }
            }
        }

        // for(auto x : dp){
        //     for(auto y : x){
        //         cout << y << " ";
        //     }
        //     cout << endl;
        // }
        cout << dp[k][n] << endl;

    }
}