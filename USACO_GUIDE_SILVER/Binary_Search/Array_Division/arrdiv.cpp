#include <bits/stdc++.h>
using namespace std;

int n , k;
vector<int> nums;

//for a given maximum sum, see if it works
bool valid(long long maxSum){
    long long curTotal = 0;
    int subarrays = 1;
    for(int i=0; i<n; i++){
        if(nums[i] + curTotal > maxSum){
            curTotal = nums[i]; subarrays++;
        }
        else{
            curTotal += nums[i];
        }
        if(subarrays > k || curTotal > maxSum) return false;
    }
    return true;
}

long long binarySearch(long long lo, long long hi){
    hi++;
    while(lo < hi){
        long long mid = lo + (hi - lo)/2;
        if(valid(mid)){
            hi = mid;
        }
        else{
            lo = mid + 1;
        }
    }
    return lo;
}

int main(){
    //freopen("arrdiv.in" , "r" , stdin);

    cin >> n >> k; nums.resize(n);
    long long totalSum = 0;
    for(int i=0; i<n; i++){
        cin >> nums[i];
        totalSum += nums[i];
    }

    //binarySearch
    cout << binarySearch(1 , totalSum) << endl;

}