#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;
const ll MAXN = 5 * 1e5;

ll fac[MAXN+1];
ll inv[MAXN+1];

ll modpow(ll x, ll exp)
{
    if(exp == 0) return 1;
    ll u = modpow(x, exp/2);
    u = (u*u)%MOD;
    if(exp%2 == 1) u = (u*x)%MOD;
    return u;
}

void factorial()
{
    fac[0] = 1;
    for(ll i=1; i<=MAXN; i++) fac[i] = (i*fac[i-1])%MOD;
}

void inverses()
{
    inv[MAXN] = modpow(fac[MAXN], MOD-2);
    for(ll i=MAXN; i>=1; i--) inv[i-1] = (i*inv[i])%MOD;
}

ll choose(ll a, ll b)
{
    return (((fac[a]*inv[b])%MOD)*(inv[a-b]))%MOD;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    factorial();
    // for(int i=0; i<10; i++) cout << fac[i] << " ";
    // cout << endl;

    inverses();
    // for(int i=0; i<10; i++) cout << inv[i] << " ";
    // cout << endl;

    // freopen("input.in", "r", stdin);

    int t; cin >> t;
    while(t--){
        ll n, k; cin >> n >> k;
        for(ll i=0; i<k; i++){
            ll r, c; cin >> r >> c;
            if(r != c) n--;
            n--;
        }
        // return 0;

        ll ans = 0;
        // cout << "n " << n << endl;
        for(ll x=(n+1)/2; x<=n; x++){
            //add n choose x to ans
            ll term = choose(n, x);
            ll mult = (fac[x]*inv[2* x-n])%MOD;
            term *= mult;
            term %= MOD;
            ans += term;
            ans %= MOD;
            // cout << ans << endl;
        }
        cout << ans << endl;
    }
}