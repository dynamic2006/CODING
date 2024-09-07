#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll MAXNUM = 1e18;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.in", "r", stdin);

    int t; cin >> t;
    while(t--){
        ll m, x; cin >> m >> x;
        ll totalH = 0;
        vector<pair<ll , ll>> months(m);
        for(ll i=0; i<m; i++){
            cin >> months[i].first >> months[i].second;
            totalH += months[i].second;
        }
        
        ll size = m*totalH;
        vector<ll> dp(size+1, MAXNUM); dp[0] = 0;
        for(ll i=0; i<m; i++){
            for(ll j=size-months[i].second; j>=0; j--){
                if(dp[j] != -1 && i*x - dp[j] - months[i].first >= 0){
                    dp[j + months[i].second] = min(dp[j+months[i].second], dp[j] + months[i].first);
                }
            }
        }

        for(ll i=size; i>=0; i--){
            if(dp[i] != MAXNUM){
                cout << i << endl;
                break;
            }
        }
    }
    
}