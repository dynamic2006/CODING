#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("subsum1.in" , "r" , stdin);
    int n, target; cin >> n >> target;
    vector<int> nums(n+1); nums[0] = 0;
    for(int i=1; i<=n; i++){
        cin >> nums[i];
    }

    int left_idx = 0, right_idx = 0;
    long long sum = 0; //left excluded, right included
    long long total_subarrays = 0;
    while(left_idx <= right_idx && right_idx <= n){
        sum -= nums[left_idx++];
        while(right_idx + 1 <= n && sum + nums[right_idx + 1] <= target){
            sum += nums[++right_idx];
            if(sum == target){
                total_subarrays++;
            }
        }
    }
    cout << total_subarrays << endl;
}