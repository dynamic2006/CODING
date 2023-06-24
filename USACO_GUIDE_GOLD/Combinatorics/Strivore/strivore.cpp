#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;
const ll MAXSIZE = 2*1e6;

ll fac[MAXSIZE+1], inv[MAXSIZE+1];
ll mod25[MAXSIZE+1], mod26[MAXSIZE+1];

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
    for(ll i=1; i<=MAXSIZE; i++){
        fac[i] = (i * fac[i-1]) % MOD;
    }
}

void fillInv(){
    inv[MAXSIZE] = modpow(fac[MAXSIZE] , MOD-2);
    for(ll i = MAXSIZE - 1; i>=0; i--){
        inv[i] = ((i+1) * (inv[i+1])) % MOD;
    }
}

ll choose(ll a, ll b){
    ll temp = (fac[a] * inv[b]) % MOD;
    return (temp * inv[a-b]) % MOD;
}

void fill25(){
    mod25[0] = 1;
    for(ll i=1; i<=MAXSIZE; i++){
        mod25[i] = (25 * mod25[i-1]) % MOD;
    }
}

void fill26(){
    mod26[0] = 1;
    for(ll i=1; i<=MAXSIZE; i++){
        mod26[i] = (26 * mod26[i-1]) % MOD;
    }
}

int main(){

    fillFac();
    fillInv();
    fill25();
    fill26();

    //freopen("strivore.in"  , "r" , stdin);

    ll k; cin >> k;
    string s; cin >> s;

    //use stars and bars
    //choose s.size() stars from overall length
    //for this arrangement, to make it unique:
    //for each character in s (chose the placements already)
    //make sure it is the first one the appear in final string
    //not counting previous characters that are from s
    //all characters in final string after last character in s
    //can therefore be any of the 26 lowercase letters
    //so we need to count the combos
    //for each possible placement of the final character in s

    ll wordSize = s.size();
    ll totalSize = wordSize + k;
    ll ans = 0;

    for(ll i=wordSize; i<=totalSize; i++){
        //out of i stars, choose wordSize for the characters in s
        //note we set last character of s as last character of this string
        //so we only choose wordSize-1 other stars
        ll term = choose(i-1, wordSize-1);
        //setting other characters that are restricted
        term = (term * mod25[i-wordSize]) % MOD;
        //setting characters that appear after final character from s
        term = (term * mod26[totalSize - i]) % MOD;
        ans = (ans + term) % MOD;
    }

    cout << ans << endl;
    return 0;

}