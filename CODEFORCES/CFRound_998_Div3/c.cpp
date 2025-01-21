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
        int n, k; cin >> n >> k;
        vector<int> nums(n);
        for(int i=0; i<n; i++) cin >> nums[i];
        sort(nums.begin(), nums.end());

        int left = 0, right = n-1;
        int counter = 0;
        while(left < right){
            int tot = nums[left] + nums[right];
            if(tot == k){
                counter++;
                left++;
                right--;
            }
            else if(tot < k) left++;
            else right--;
        }

        cout << counter << endl;
    }
}