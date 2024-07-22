#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("values.in", "r", stdin);

    int n, k; cin >> n >> k;
    vector<int> coins(n);
    for(int i=0; i<n; i++) cin >> coins[i];

    vector<vector<bool>> dp(k+1, vector<bool>(k+1, false)); dp[0][0] = true;
    for(auto &c : coins){
        for(int i=k; i>=c; i--){
            for(int j=0; j<=k; j++){
                if(!dp[i][j]) dp[i][j] = dp[i-c][j];
                if(j<=k-c && !dp[i][j+c]) dp[i][j+c] = dp[i-c][j];
            }
        }
    }

    int ans = 0;
    for(int i=0; i<=k; i++) if(dp[k][i]) ans++;
    cout << ans << endl;
    for(int i=0; i<=k; i++) if(dp[k][i]) cout << i << " ";
    cout << endl;
}