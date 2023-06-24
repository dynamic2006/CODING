#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> arr;

//can the array be split into at most k subarrays
//such that the max sum of any of them is less than sum
bool valid(long long sum){
    long long curSum = 0 , totalArrs = 1;
    for(int i=0; i<n; i++){
        if(arr[i] > sum) return false;
        if(curSum + arr[i] > sum){
            totalArrs++; curSum = 0;
        }
        curSum += arr[i];
    }
    if(totalArrs <= k) return true;
    return false;
}

long long binarySearch(long long lo , long long hi){
    hi++;
    while(lo < hi){
        long long mid = lo + (hi - lo)/2;
        if(valid(mid)) hi = mid;
        else lo = mid+1;
    }
    return lo;
}

int main(){

    //freopen("arrdiv.in" , "r" , stdin);
    
    cin >> n >> k;
    for(int i=0; i<n; i++){
        int x; cin >> x;
        arr.push_back(x);
    }

    cout << binarySearch(0 , n * 1e9) << endl;

}