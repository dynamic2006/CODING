#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MAXNUM = 1e6+1;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("coins.in", "r", stdin);

    int n, x; cin >> n >> x;
    vector<int> coins(n);
    for(int i=0; i<n; i++) cin >> coins[i];

    vector<int> dp(MAXNUM, MAXNUM);
    for(int i=0; i<n; i++) dp[coins[i]] = 1;

    for(int i=0; i<=MAXNUM; i++){
        for(int j=0; j<n; j++){
            if(coins[j] < i) dp[i] = min(dp[i], dp[i - coins[j]] + 1);
        }
    }

    if(dp[x] != MAXNUM) cout << dp[x] << endl;
    else cout << -1 << endl;
}