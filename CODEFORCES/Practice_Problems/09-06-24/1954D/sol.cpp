#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll MOD = 998244353;
const ll MAXNUM = 5000;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.in", "r", stdin);

    ll n; cin >> n;
    vector<ll> a(n);
    for(ll i=0; i<n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    vector<ll> dp(MAXNUM+1, 0); dp[0] = 1;
    ll ans = 0;

    for(ll i=0; i<n; i++){
        for(ll j=MAXNUM-a[i]; j>=0; j--){
            ll idx = j+a[i];
            dp[idx] += dp[j];
            dp[idx] %= MOD;
            if(idx <= 2*a[i]){
                ll term = (a[i] - ((idx+1)/2))*(dp[j]);
                // cout << "j=" << j << " a[i]=" << a[i] << " term " << term << endl;
                term %= MOD;
                ans += term;
                // cout << "ANS " << ans << endl;
                ans %= MOD;
            }
        }
    }

    // for(int i=0; i<=100; i++){
    //     cout << i << ":" << dp[i] << " ";
    //     if(i%10 == 0)cout << endl;
    // }
    // cout << endl;

    for(ll i=1; i<=MAXNUM; i++){
        // cout << "i " << i << " dp[i]=" << dp[i] << endl;
        ll term = ((i+1)/2)*(dp[i]);
        term %= MOD;
        ans += term;
        ans %= MOD;
        // cout << "term " << term << " ans " << ans << endl;
    }
    cout << ans << endl;

}