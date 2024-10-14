#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;

ll modpow(ll x, ll exp)
{
    if(exp == 0) return 1;
    ll u = modpow(x, exp/2);
    u = (u*u) % MOD;
    if(exp%2 == 1) u = (u*x) % MOD;
    return u;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.in", "r", stdin);

    ll t; cin >> t;
    vector<ll> n(t), k(t);
    for(ll i=0; i<t; i++) cin >> n[i];
    for(ll i=0; i<t; i++) cin >> k[i];

    for(ll i=0; i<t; i++){
        ll exp = k[i];
        ll ans = modpow(2, exp);
        cout << ans << endl;
    }
}