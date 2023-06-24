#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;

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

int main() {

    //freopen("divisor.in" , "r" , stdin);

    //# of divisors is product of each exp+1
    //sum = product of geometric series
    //product = number ^ (# of divisors / 2)

    //NOTE!!
    //due to large numbers + modulo
    //we instead calculate product using "recursion"

    //specifically, P_i = product of first i distinct parts of prime factorization
    //and we let k_i be exponent for x_i, the ith prime
    //then P_i = ( (P_(i-1)) ^ (k_i + 1) )   *   ( ( x ^ ((k_i)*(k_i + 1)/2))  ^  (num_i) )
    //where num_i is the number of calculated divisors before we reached the ith part

    //and we want ((k_i)*(k_i + 1)/2) modulo MOD-1 (fermat's thm)
    //so we take (k_i)*(k_i + 1) modulo 2*(MOD-1) so we can easily divide by 2 after


    ll num = 1, sum = 1, prod = 1, expNum = 1;
    ll n; cin >> n;
    for(ll i=0; i<n; i++){
        ll p, k; cin >> p >> k;

        num = (num * (k+1)) % MOD;
        
        ll sumTerm = (modpow(p, k+1) - 1) * (modpow(p-1, MOD-2)) % MOD;
        sum = (sum * sumTerm) % MOD;

        ll exp = ((k) * (k+1)) % (2*(MOD-1)); exp /= 2;
        exp = (exp * expNum) % (MOD-1);
        ll prodTerm = modpow(p, exp);
        prod = modpow(prod, k+1) % MOD;
        prod = (prod * prodTerm) % MOD;

        expNum = (expNum * (k+1)) % (MOD-1);
    }

    cout << num << " " << sum << " " << prod << endl;
    return 0;
}