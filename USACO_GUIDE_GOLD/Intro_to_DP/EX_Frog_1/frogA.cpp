#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("frog1.in", "r", stdin);

    int n; cin >> n;
    vector<int> heights(n);
    for(int i=0; i<n; i++) cin >> heights[i];

    vector<int> dp(n);
    dp[n-1] = 0;
    dp[n-2] = abs(heights[n-1] - heights[n-2]);
    for(int i=n-3; i>=0; i--){
        dp[i] = min(abs(heights[i+1] - heights[i]) + dp[i+1], abs(heights[i+2] - heights[i]) + dp[i+2]);
    }

    cout << dp[0] << endl;
}