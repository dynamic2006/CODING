#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;
const ll MAXN = 1e6;

ll fac[MAXN+1];
ll inv[MAXN+1];

ll modpow(ll x, ll n)
{
    if(n == 0) return 1;
    ll u = modpow(x, n/2);
    u = (u*u)%MOD;
    if(n%2) u = (u*x)%MOD;
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

ll choose(ll n, ll r)
{
    return (fac[n] * inv[r] % MOD)*(inv[n-r] % MOD) % MOD;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    factorial();
    inverses();

    // freopen("input.in", "r", stdin);

    //catalan numbers
    //1/n+1 *(2n choose n)

    ll n; cin >> n;
    if(n%2){
        cout << 0 << endl;
        return 0;
    }

    n/=2;
    ll ans = choose(2*n, n);
    ll den = modpow(n+1, MOD-2);
    ans *= den; ans %= MOD;
    cout << ans << endl;

}