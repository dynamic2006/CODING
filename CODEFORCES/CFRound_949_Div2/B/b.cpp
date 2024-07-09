#include <bits/stdc++.h>
using namespace std;

int main()
{
    // freopen("b.in" , "r" , stdin);

    vector<int> nums, prevNums;

    for(int i=0; i<=50; i++){
        nums.push_back(i);
        prevNums.push_back(i);
    }

    for(int r=0; r<5; r++){
        for(int i=0; i<=50; i++){
            if(i == 0) nums[i] = prevNums[i] | prevNums[i+1];
            else nums[i] = prevNums[i-1] | prevNums[i] | prevNums[i+1];
            cout << i << " " << nums[i] << endl;
        }
        for(int i=0; i<=50; i++){
            prevNums[i] = nums[i];
        }
        cout << endl;
    }
    
    // int t; cin >> t;
    // while(t--){
    //     int n, m; cin >> n >> m;

    //     if(m == 0){
    //         cout << n << endl;
    //         continue;
    //     }

    //     int k = 1;
    //     while(k < n+m) k = k*2 + 1;
    //     cout << k << endl;
    // }
}