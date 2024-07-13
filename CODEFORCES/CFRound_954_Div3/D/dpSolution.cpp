#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("d.in" , "r" , stdin);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string s; cin >> s;

        vector<vector<int>> dp(2, vector<int>(n, 0));
        dp[0][0] = s[0] - '0';
        for(int i=1; i<n; i++){
            int val0 = s[i] - '0';
            int val1 = 10*(s[i-1] - '0') + val0;

            dp[0][i] = min(dp[0][i-1] + val0, dp[0][i-1] * val0);

            if(i == 1) dp[1][i] = val1;
            else dp[1][i] = min({dp[0][i-2] * val1, dp[0][i-2] + val1, dp[1][i-1] * val0, dp[1][i-1] + val0});
        }
        cout << dp[1][n-1] << endl;
    }
}