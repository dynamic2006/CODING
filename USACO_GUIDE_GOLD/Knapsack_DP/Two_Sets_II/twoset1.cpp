#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("twoset.in", "r", stdin);

    int n; cin >> n;
    if(n % 4 != 0 && n % 4 != 3){
        cout << 0 << endl;
        return 0;
    }

    int k = n*(n+1)/4;
    vector<ll> dp(k+1, 0); dp[0] = 1;
    for(int i=1; i<=n-1; i++){
        for(int j=k; j>=i; j--){
            dp[j] += dp[j-i];
            //cout << j << " " << dp[j] << endl;
            dp[j] %= MOD;
        }
    }
    cout << dp[k] << endl;
}