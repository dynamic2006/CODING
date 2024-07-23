#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("c.in", "r", stdin);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<ll> nums(n);
        for(int i=0; i<n; i++) cin >> nums[i];

        int ans = 0;
        for(int i=1; i<n; i++){
            if(nums[i] == 1 && nums[i] < nums[i-1]){
                ans = -1; break;
            }
            while(nums[i] < nums[i-1]){
                ans++;
                nums[i] = nums[i] * nums[i];
            }
        }
    }
}