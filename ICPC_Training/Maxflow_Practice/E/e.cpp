#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<ll> dp(25, 0);
    dp[1] = 1; dp[2] = 2; dp[3] = 4;
    for(int i=4; i<25; i++){
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }

    // freopen("input.in", "r", stdin);

    int n; cin >> n;
    cout << dp[n] << endl;

}