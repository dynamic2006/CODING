#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MAXN = 1e6;

ll dp[MAXN+1];

int main(){

    fill(dp, dp+MAXN+1, -1);

    //freopen("coins.in" , "r" , stdin);

    ll n, x; cin >> n >> x;
    vector<ll> values(n);
    for(ll i=0; i<n; i++){
        cin >> values[i];
    }
    sort(values.begin() , values.end());

    //cout << "X = " << x << endl;

    dp[0] = 0;
    for(ll i=1; i<=x; i++){
        for(ll j=0; j<n; j++){
            if(values[j] > i) break;
            if(dp[i-values[j]] == -1) continue;

            if(dp[i] == -1) dp[i] = dp[i-values[j]] + 1;
            else dp[i] = min(dp[i] , dp[i-values[j]] + 1);
        }
        //cout << i << " " << dp[i] << endl;
    }

    cout << dp[x] << endl;
    return 0;

}