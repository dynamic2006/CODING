#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MAXNUM = 200000;

ll n, sieve[MAXNUM+1];
map<pair<ll, ll> , ll> occs;
map<ll, ll> ansFactors;

void fillSieve(){
    sieve[0] = 0;
    sieve[1] = 1;
    for(ll i=2; i<=MAXNUM; i++){
        if(sieve[i] != 0) continue;
        for(ll j=i; j<=MAXNUM; j+=i){
            sieve[j] = i;
        }
    }
}

void factorize(ll k){
    while(k > 1){
        ll p = sieve[k];
        ll exp = 0;
        while(k % p == 0){
            k /= p;
            exp++;
            occs[{p,exp}]++;
            if(occs[{p,exp}] >= n-1 && ansFactors[p] < exp){
                ansFactors[p] = exp;
            }
        }

    }
}

int main(){

    fillSieve();

    //freopen("orac.in" , "r" , stdin);

    //factorize each number
    //if a factor appears in atleast n-1 numbers
    //then it must appear in the final GCD

    cin >> n;
    for(ll i=0; i<n; i++){
        ll x; cin >> x;
        factorize(x);
    }

    ll ans = 1;

    for(auto k : ansFactors){
        //cout << k.first << " " << k.second << endl;
        ans *= pow(k.first, k.second);
    }

    cout << ans << endl;
    return 0;

}