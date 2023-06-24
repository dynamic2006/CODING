#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;
const ll MAXN = 1e6;

ll fac[MAXN+1], inv[MAXN+1];

ll modPow(ll x, ll y){
    if(y == 0) return 1;
    if(y % 2 == 0){
        ll k = modPow(x, y/2);
        return (k*k) % MOD;
    }
    else{
        ll k = modPow(x, y-1);
        return (k*x) % MOD;
    }
}

void fillFac(){
    fac[0] = 1;
    for(ll i=1; i<=MAXN; i++){
        fac[i] = (i*fac[i-1]) % MOD;
    }
}

void fillInv(){
    inv[MAXN] = modPow(fac[MAXN], MOD-2);
    for(ll i=MAXN-1; i>=0; i--){
        inv[i] = ((i+1)*(inv[i+1])) % MOD;
    }
}

int main(){

    fillFac();
    fillInv();

    //freopen("creating.in" , "r" , stdin);

    map<char, ll> occ;

    string s; cin >> s;
    for(ll i=0; i<s.size(); i++){
        occ[s[i]]++;
    }

    ll ans = fac[s.size()];
    for(auto pair : occ){
        ans = ((ans * inv[pair.second]) % MOD);
    }

    cout << ans << endl;
    return 0;

}