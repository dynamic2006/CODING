#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){

    //freopen("div_game.in" , "r" , stdin);

    ll n; cin >> n;

    ll temp = n, ans = 0;
    for(ll i=2; i*i <= n; i++){
        
        ll exp = 0;
        while(temp % i == 0){
            temp /= i;
            exp++;
        }

        ll k = 1;
        while(exp >= k){
            ans++;
            exp -= k;
            k++;
        }
    }

    //note that temp is now either 1
    //OR it can be the largest prime factor of n
    //to prove this, we use contradiction
    //if temp is product of atleast two primes
    //then both must have been unaccounted for
    //so both primes are above sqrt(n)
    //so temp > (sqrt(n))^2, so temp > n
    //but temp divides n, so this must be false
    //small note: temp must contain n's largest prime factor
    //since temp was constructed by repeatedly dividing n
    
    //so we only need to add 1 to the answer
    //in the case that temp > 1 (one more prime factor)
    if(temp > 1) ans++;
    cout << ans << endl;
    return 0;

   
}