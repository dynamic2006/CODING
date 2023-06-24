#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MAXN = 20;
const ll MAXNUM = 1e9;

int main(){

    //freopen("stalling.in" , "r" , stdin);

    //two pointers strategy
    //sort cows and stalls
    //then use greedy + 2 ptrs

    ll n; cin >> n;
    vector<ll> cows(n), heights(n);
    for(ll i=0; i<n; i++){
        cin >> cows[i];
    }
    for(ll i=0; i<n; i++){
        cin >> heights[i];
    }

    sort(cows.begin() , cows.end() , greater<ll>());
    sort(heights.begin() , heights.end() , greater<ll>());

    ll ans = 1;
    ll l = 0, r = 0, c = 0;
    while(l < n){
        while(r < n && cows[c] <= heights[r]) r++;
        if(r <= l){
            ans = 0; break;
        }
        ans *= (r-l);
        l++; c++;
    }

    cout << ans << endl;
    return 0;

}
