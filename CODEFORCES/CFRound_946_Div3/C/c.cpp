#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("c.in" , "r" , stdin);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> nums(n);
        for(int i=0; i<n; i++) cin >> nums[i];

        map<tuple<int, int, int>, int> validPairs, count;
        validPairs.clear(); count.clear();
        long long ans = 0;
        for(int i=2; i<n; i++){
            ans += validPairs[{0, nums[i-1], nums[i]}]++;
            ans += validPairs[{nums[i-2], 0, nums[i]}]++;
            ans += validPairs[{nums[i-2], nums[i-1], 0}]++;
            ans -= 3*count[{nums[i-2], nums[i-1], nums[i]}]++;
        }

        cout << ans << endl;
    }

}