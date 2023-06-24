#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MAX = 1e9 + 7;

//recursive function to calculate modulo
//if exp is divisible by 2, do this and return x^2
//else subtract 1 and return x*num
ll calcMod(ll num, ll exp){
    if(exp == 0) return 1;
    if(exp % 2 == 0){
        ll x = calcMod(num, exp/2);
        return (x*x % MAX);
    }
    else{
        ll x = calcMod(num, exp - 1);
        return (x*num % MAX);
    }
}

int main(){

    //freopen("exponentiation.in" , "r" , stdin);

    ll n; cin >> n;
    for(ll i=0; i<n; i++){
        ll a, b; cin >> a >> b;
        cout << calcMod(a,b) << endl;
    }
    return 0;

}