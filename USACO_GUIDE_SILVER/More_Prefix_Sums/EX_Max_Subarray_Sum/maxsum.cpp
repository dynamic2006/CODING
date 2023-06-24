#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("maxsum.in" , "r" , stdin);

    int n; cin >> n;
    long long min_prefix_sum = 0, max_subarray_sum = -10e9 - 1;
    vector<int> nums(n+1); nums[0] = 0;
    vector<long long> prefix_sums(n+1); prefix_sums[0] = 0;
    for(int i=1; i<=n; i++){
        cin >> nums[i];
        prefix_sums[i] = prefix_sums[i-1] + nums[i];
        max_subarray_sum = max(max_subarray_sum , prefix_sums[i] - min_prefix_sum);
        min_prefix_sum = min(min_prefix_sum , prefix_sums[i]);
    }
    cout << max_subarray_sum << endl;
}