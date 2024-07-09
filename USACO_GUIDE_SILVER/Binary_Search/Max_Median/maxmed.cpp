#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> nums;

bool valid(int m){
    vector<int> prefix(n+1), minSum(n+1);
    prefix[0] = 0; minSum[0] = 0;

    for(int i=1; i<=n; i++){
        prefix[i] = prefix[i-1];
        if(nums[i-1] >= m) prefix[i]++;
        else prefix[i]--;

        minSum[i] = min(minSum[i-1], prefix[i]);

        if(i < k) continue;
        if(prefix[i] - minSum[i-k] > 0) return true;
    }
    return false;
}

//binarySearch on max value of median m
int binarySearch(int lo, int hi){
    lo--;
    while(lo<hi){
        int mid = lo + (hi-lo+1)/2;
        if(valid(mid)) lo=mid;
        else hi = mid-1;
    }
    return lo;
}

int main()
{
    //freopen("maxmed.in" , "r" , stdin);

    cin >> n >> k;
    nums.resize(n);
    for(int i=0; i<n; i++) cin >> nums[i];

    int ans = binarySearch(0, n);
    cout << ans << endl;

}
//IDEAS
//binary search on max median value m
//checking if m is valid is a subproblem: max subarray sum
//where values are # of prev elements greater than m - # of prev elements less than m
//if there exists max subarray len x with sum k > 0 then m is valid