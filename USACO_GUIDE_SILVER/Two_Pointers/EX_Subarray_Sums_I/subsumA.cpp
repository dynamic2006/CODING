#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("subsum1.in", "r", stdin);

    ll n, x; cin >> n >> x;
    vector<ll> nums(n);
    for(int i=0; i<n; i++) cin >> nums[i];

    int l=0, r=-1;
    ll ans = 0, curTotal = 0;
    while(l<n){
        while(curTotal < x && r+1 < n){
            curTotal += nums[++r];
        }
        if(curTotal == x) ans++;
        curTotal -= nums[l++];
    }
    cout << ans << endl;
}