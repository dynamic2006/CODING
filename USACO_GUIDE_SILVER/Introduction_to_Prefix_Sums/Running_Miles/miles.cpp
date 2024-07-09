#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("miles.in" , "r" , stdin);

    int tt; cin >> tt;
    for(int t=0; t<tt; t++){
        int n; cin >> n;
        vector<int> nums(n);
        vector<int> prefixMax(n), suffixMax(n);

        nums.resize(n);
        for(int i=0; i<n; i++) cin >> nums[i];
        prefixMax[0] = 0;
        for(int i=1; i<n; i++){
            int diff = i - prefixMax[i-1];
            if(nums[i] >= nums[prefixMax[i-1]] - diff) prefixMax[i] = i;
            else prefixMax[i] = prefixMax[i-1];
        }
        suffixMax[n-1] = n-1;
        for(int i=n-2; i>=0; i--){
            int diff = suffixMax[i+1] - i;
            if(nums[i] >= nums[suffixMax[i+1]]-diff) suffixMax[i] = i;
            else suffixMax[i] = suffixMax[i+1];
        }

        //DEBUG
        // for(auto x : prefixMax) cout << x << " ";
        // cout << endl;
        // for(auto x : suffixMax) cout << x << " ";
        // cout << endl;

        int ans = 0;
        for(int i=1; i<n-1; i++){
            int sum = nums[prefixMax[i-1]] + nums[suffixMax[i+1]] + nums[i] + (prefixMax[i-1] - suffixMax[i+1]);
            ans = max(ans, sum);
            //cout << "ANS " << ans << " " << prefixMax[i-1] << " " << suffixMax[i+1] << endl;
        }
        cout << ans << endl;
    }
}