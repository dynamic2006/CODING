#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("c.in", "r", stdin);

    int t; cin >> t;
    while(t--){
        ll n, k; cin >> n >> k;
        vector<ll> nums(n);
        for(ll i=0; i<n; i++) cin >> nums[i];
        sort(nums.begin(), nums.end(), greater<int>());

        ll ans = 0, minus = 0;
        for(ll i=0; i<n; i++){
            if(i%2 == 1){
                ans -= nums[i];
                ll sub = min(k, nums[i-1]-nums[i]);
                k -= sub;
                minus += sub;
            }
            else ans += nums[i];
        }
        ans -= minus;
        cout << ans << endl;
    }
}