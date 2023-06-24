#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){

    //freopen("perms.in" , "r" , stdin);

    ll n, k; cin >> n >> k;

    //note k can only go up to 4
    //this means we can just store the derangements
    //for k=1, k=2, k=3, and k=4
    //and just calculate the answer with that

    ll derangements[4];
    derangements[0] = 0;
    derangements[1] = 1;
    derangements[2] = 2;
    derangements[3] = 9;

    ll ans = 1;

    for(ll i=0; i<k; i++){
        ll term = 1;
        for(ll j=0; j<=i; j++){
            term *= (n-j);
            term /= (j+1);
        }
        term *= derangements[i];
        ans += term;
    }

    cout << ans << endl;
    return 0;

}