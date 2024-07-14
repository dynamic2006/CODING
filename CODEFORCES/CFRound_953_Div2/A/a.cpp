#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("a.in" , "r" , stdin);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> nums(n);
        for(int i=0; i<n; i++) cin >> nums[i];

        int maxNum = 0;
        for(int i=0; i<n-1; i++) maxNum = max(nums[i] , maxNum);

        cout << maxNum + nums[n-1] << endl;
    }
}