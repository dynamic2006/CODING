#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;

//same as example, just use fermats little thm
//a^(b^c) % MOD -- first find b^c % (MOD-1)
//since the modulo is a prime number, this works
ll expMod(ll num, ll exp, ll mod){
    if(exp == 0) return 1;
    if(exp % 2 == 0){
        ll k = expMod(num, exp/2, mod);
        return (k*k % mod);
    }
    else{
        ll k = expMod(num, exp-1, mod);
        return (num*k % mod);
    }
}

int main(){
    
    //freopen("exp2.in" , "r" , stdin);

    ll n; cin >> n;
    for(ll i=0; i<n; i++){
        ll a, b, c; cin >> a >> b >> c;
        ll tempExp = expMod(b, c, MOD-1);
        cout << expMod(a, tempExp, MOD) << endl;
    }
    return 0;

}