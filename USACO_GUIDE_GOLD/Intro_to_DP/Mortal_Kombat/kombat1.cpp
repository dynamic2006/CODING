#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MAXNUM = 1e6;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("kombat.in", "r", stdin);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n);
        for(int i=0; i<n; i++) cin >> a[i];

        vector<vector<int>> dp(2, vector<int>(n, 0));
        dp[0][0] = MAXNUM; dp[1][0] = a[0];
        for(int i=1; i<n; i++) {
            if(i == 1){
                dp[0][i] = dp[1][i-1];
                dp[1][i] = dp[1][i-1] + a[i];
                continue;
            }
            dp[0][i] = min(dp[1][i-1] , dp[1][i-2]);
            dp[1][i] = min(dp[0][i-1] + a[i] , dp[0][i-2] + a[i] + a[i-1]);
        }
        // for(int i=0; i<2; i++){
        //     for(int j=0; j<n; j++){
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        cout << min(dp[0][n-1] , dp[1][n-1]) << endl;
    }
}