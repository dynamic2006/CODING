#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 1e9 +  7;
const ll MAXN = 1e6;

ll fac[MAXN + 1];
ll inv[MAXN + 1];

ll modpow(ll x, ll n, ll m){
    if(n == 0) return 1;
    if(n % 2 == 0){
        ll k = modpow(x, n/2, m);
        return (k*k) % m;
    }
    else{
        ll k = modpow(x, n-1, m);
        return (k*x) % m;
    }
}

void fillFac(ll mod){
    fac[0] = 1;
    for(int i=1; i<=MAXN; i++){
        fac[i] = (i*fac[i-1]) % mod;
    }
}

void fillInv(ll mod){
    //idea here is that MOD is prime
    //so anything raised to MOD-1 congruent to 1
    //by Fermat's little thm
    //so x inverse times x = 1, so inverse = x ^ (MOD-2)
    inv[MAXN] = modpow(fac[MAXN] , mod-2, mod);
    for(ll i=MAXN-1; i>=0; i--){
        inv[i] = ((i+1)*inv[i+1]) % mod;
    }
}

ll choose(ll n, ll k, ll m){
    return (((fac[n] * inv[k]) % m) * (inv[n-k])) % m;
}

int main(){

    fillFac(MOD);
    fillInv(MOD);

    //freopen("coeff.in" , "r" , stdin);

    ll n; cin >> n;
    for(ll i=0; i<n; i++){
        ll a, b; cin >> a >> b;
        cout << choose(a, b, MOD) << endl;
    }

}