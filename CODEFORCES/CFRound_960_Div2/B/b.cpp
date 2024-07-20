#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("b.in" , "r" , stdin);

    int t; cin >> t;
    while(t--){
        int n, x, y; cin >> n >> x >> y;
        vector<int> nums(n,0); int sign = -1;
        for(int i=y-1; i>=1; i--){
            nums[i-1] = sign;
            sign = -sign;
        }
        for(int i=y; i<=x; i++) nums[i-1] = 1;
        sign = -1;
        for(int i=x+1; i<=n; i++){
            nums[i-1] = sign;
            sign = -sign;
        }

        for(auto num : nums) cout << num << " ";
        cout << endl;
    }
}