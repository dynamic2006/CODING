#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;
const ll MAXN = 1e12;
const ll INV2 = 5*1e8 + 4;

int main(){

    //freopen("sum.in" , "r" , stdin);

    ll n; cin >> n;
    ll ans = 0;

    ll i=1, sub=1;
    while(i*i <= n){
        ll k = n/i;
        ll add = (i * (k - sub)) % MOD;
        ans = (ans + add) % MOD;
        ll extra = (((i + k) % MOD)*((k-i+1) % MOD)) % MOD;
        extra = (extra * INV2) % MOD;
        ans = (ans + extra) % MOD;
        i++; sub++;
    }

    cout << ans << endl;
    return 0;

}