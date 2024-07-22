#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MAXNUM = 1e5+1;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("money.in", "r", stdin);

    int n; cin >> n;
    vector<int> coins(n);
    for(int i=0; i<n; i++) cin >> coins[i];
    vector<bool> dp(MAXNUM, false); dp[0] = true;
    for(auto &c : coins){
        for(int i=MAXNUM; i>=c; i--){
            if(!dp[i]) dp[i] = dp[i-c];
        }
    }

    int ans = 0;
    for(int i=1; i<=MAXNUM; i++) if(dp[i]) ans++;
    cout << ans << endl;
    for(int i=1; i<=MAXNUM; i++) if(dp[i]) cout << i << " ";
    cout << endl;
}