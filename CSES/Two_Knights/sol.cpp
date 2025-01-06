#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 10001;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll dp[N];

    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 6;
    dp[3] = 28;
    dp[4] = 24;

    for(int i=5; i<=N; i++){
        if(i<N) dp[i] = dp[i-1] + 8*i - 16;
        ll x = (i-1)*(i-1);
        dp[i-1] = (x*(x-1))/2 - dp[i-1];
    }

    // freopen("input.in", "r", stdin);

    int n; cin >> n;
    for(int i=1; i<=n; i++){
        cout << dp[i] << endl;
    }

}