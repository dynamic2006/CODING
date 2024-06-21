#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> nums;
vector<int> lastVals;
vector<vector<int>> arrs;

int binarySearch(int num)
{
    int lo = 0, hi = lastVals.size();
    while(lo<hi){
        int mid = lo+(hi-lo)/2;
        if(lastVals[mid] < num) hi=mid;
        else lo=mid+1;
    }
    return lo;
}

int main()
{
    //freopen("prepmerge.in" , "r" , stdin);

    cin >> n;
    nums.resize(n);
    for(int i=0; i<n; i++){
        cin >> nums[i];
    }

    for(auto num : nums){
        int index = binarySearch(num);
        if(index == lastVals.size()){
            lastVals.push_back(num);
            arrs.push_back({num});
        }
        else{
            lastVals[index] = num;
            arrs[index].push_back(num);
        }
    }

    for(auto arr : arrs){
        for(auto num : arr){
            cout << num << " ";
        }
        cout << endl;
    }
}
//IDEAS
//keep track of each new merge vector formed
//binary seach thru last elements added in each vector
//first vector to have element lower than cur element, add cur element to end
//if no vectors have element lower than cur, then add new vector with cur at end
