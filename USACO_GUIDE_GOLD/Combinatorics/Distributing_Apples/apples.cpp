#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;
const ll MAXN = 1e6;

ll fac[2*MAXN+2], inv[2*MAXN+2];

ll modPow(ll x, ll n){
    if(n == 0) return 1;
    if(n % 2 == 0){
        ll k = modPow(x, n/2);
        return (k*k) % MOD;
    }
    else{
        ll k = modPow(x, n-1);
        return (k*x) % MOD;
    }
}

void fillFac(ll size){
    fac[0] = 1;
    for(ll i=1; i<size; i++){
        fac[i] = (i * fac[i-1]) % MOD;
    }
}

void fillInv(ll size){
    inv[size-1] = modPow(fac[size-1], MOD-2);
    for(ll i=size-2; i>=0; i--){
        inv[i] = ((i+1)*(inv[i+1])) % MOD;
    }
}

int main(){

    fillFac(2*MAXN+2);
    fillInv(2*MAXN+2);

    //freopen("apples.in" , "r" , stdin);

    ll n, m; cin >> n >> m;

    ll ans = fac[n+m-1];
    //cout << ans << endl;
    ans = (ans * inv[m]) % MOD;
    //cout << ans << endl;
    ans = (ans * inv[n-1]) % MOD;
    cout << ans << endl;

    return 0;

}