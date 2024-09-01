#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;

ll modpow(ll x, ll exp){
    if(exp == 0) return 1;

    ll u = modpow(x, exp/2);
    u = (u*u)%MOD;
    if(exp%2 == 1) u = (u*x) % MOD;
    return u;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("f.in", "r", stdin);

    int t; cin >> t;
    while(t--){
        ll n; cin >> n;
        vector<ll> a(n);
        for(ll i=0; i<n; i++){
            cin >> a[i];
        }
        vector<ll> prefix(n); prefix[0] = a[0];
        for(ll i=0; i<n; i++){
            prefix[i] = prefix[i-1] + a[i];
            prefix[i] %= MOD;
        }

        ll numerator = 0;
        for(ll i=0; i<n; i++){
            ll diff = (prefix[n-1] - prefix[i])%MOD;
            if(diff < 0) diff += MOD;
            ll add = (diff)*a[i];
            add %= MOD;
            numerator += add;
            numerator %= MOD;
        }

        ll denominator = (n*(n-1))/2; denominator %= MOD;
        denominator = modpow(denominator, MOD-2);

        ll ans = ((numerator%MOD)*(denominator%MOD))%MOD;
        cout << ans << endl;
    }
}