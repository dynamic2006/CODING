#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;
const ll MAXN = 2 * 1e6 + 2;

ll fac[MAXN+1], inv[MAXN+1];

ll modpow(ll x, ll exp){
    if(exp == 0) return 1;
    if(exp % 2 == 0){
        ll k = modpow(x, exp/2);
        return (k*k) % MOD;
    }
    else{
        ll k = modpow(x, exp-1);
        return (x*k) % MOD;
    }
}

void fillFac(){
    fac[0] = 1;
    for(ll i=1; i<=MAXN; i++){
        fac[i] = (i * fac[i-1]) % MOD;
    }
}

void fillInv(){
    inv[MAXN] = modpow(fac[MAXN] , MOD-2);
    for(ll i = MAXN-1; i>=0; i--){
        inv[i] = ((i+1)*(inv[i+1])) % MOD;
    }
}

ll choose(ll a, ll b){
    ll temp = (fac[a] * inv[b]) % MOD;
    return (temp * inv[a-b]) % MOD;
}

int main(){

    fillFac();
    fillInv();

    freopen("bots.in" , "r" , stdin);

    ll n; cin >> n;
    ll ans = choose(2*(n+1) , n+1);
    
    cout << (ans-1) % MOD << endl;
    return 0;

}