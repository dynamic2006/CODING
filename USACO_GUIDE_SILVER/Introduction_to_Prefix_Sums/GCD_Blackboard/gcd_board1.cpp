#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("gcd_board.in" , "r" , stdin);

    int n; cin >> n;
    vector<int> nums(n);
    vector<int> prefixGCD(n), suffixGCD(n);

    for(int i=0; i<n; i++) cin >> nums[i];

    prefixGCD[0] = nums[0];
    for(int i=1; i<n; i++) prefixGCD[i] = __gcd(prefixGCD[i-1], nums[i]);
    suffixGCD[n-1] = nums[n-1];
    for(int i=n-2; i>=0; i--) suffixGCD[i] = __gcd(suffixGCD[i+1], nums[i]);

    int ans = max(suffixGCD[1] , prefixGCD[n-2]);
    for(int i=1; i<n-1; i++){
        ans = max(ans , __gcd(prefixGCD[i-1] , suffixGCD[i+1]));
    }
    cout << ans << endl;
}