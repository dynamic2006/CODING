#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("shop.in", "r", stdin);

    int n, x; cin >> n >> x;
    vector<pair<int, int>> books(n+1, {0,0});
    for(int i=1; i<=n; i++) cin >> books[i].first;
    for(int i=1; i<=n; i++) cin >> books[i].second;

    vector<vector<int>> dp(n+1, vector<int>(x+1, 0));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=x; j++){
            dp[i][j] = dp[i-1][j];
            if(books[i].first <= j) dp[i][j] = max(dp[i][j], dp[i-1][j-books[i].first] + books[i].second);
        }
    }

    cout << dp[n][x] << endl;

}