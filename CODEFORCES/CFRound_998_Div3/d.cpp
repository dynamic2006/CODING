#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.in", "r", stdin);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> nums(n);
        for(int i=0; i<n; i++) cin >> nums[i];

        for(int i=1; i<n; i++){
            if(nums[i] >= nums[i-1]){
                nums[i] -= nums[i-1];
                nums[i-1] = 0;
            }
        }

        bool valid = true;
        for(int i=1; i<n; i++){
            if(nums[i] < nums[i-1]) valid = false;
        }
        if(valid) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}