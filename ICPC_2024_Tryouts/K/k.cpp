#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.in", "r", stdin);

    int n, m; cin >> n >> m;
    vector<ll> expected(n+1), actual(m+1);
    for(int i=1; i<=n; i++) cin >> expected[i];
    for(int i=1; i<=m; i++) cin >> actual[i];

    vector<vector<ll>> dp(n+1, vector<ll>(m+1, 0));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            ll diff = abs(expected[i] - actual[j]);
            if(diff <= 15) dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 7);
            else if(diff <= 23) dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 6);
            else if(diff <= 43) dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 4);
            else if(diff <= 102) dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 2);
        }
    }

    cout << dp[n][m] << endl;



}