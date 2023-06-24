#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    
    ll n; cin >> n;
    vector<ll> nums(n);
    //i = starting index
    //value.key = gcd
    //value.value = length
    vector<map<ll, ll>> gcds(n);

    for(ll i=0; i<n; i++) cin >> nums[i];

    //for each number k
    //calculate gcds that end with k
    //and update lengths as you go
    for(ll i=0; i<n; i++){
        ll k = nums[i];
        gcds[i][k] = 1; //just this number
        if(i == 0) continue;

        for(auto x : gcds[i-1]){
            ll curGCD = __gcd(x.first, k);
            //stores longest length
            //that has gcd of curGCD
            //and ends with k, the ith num
            gcds[i][curGCD] = max(gcds[i][curGCD], x.second + 1);
        }
    }

    vector<ll> ans(n);
    for(auto m : gcds){
        for(auto k : m){
            ll length = k.second-1;
            ll gcd = k.first;
            ans[length] = max(ans[length], gcd);
        }
    }
    for(auto x : ans) cout << x << " ";
    cout << endl;
    return;

}

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    //freopen("gcd.in" , "r" , stdin);

    ll t; cin >> t;
    while(t--){
        solve();
    }

}