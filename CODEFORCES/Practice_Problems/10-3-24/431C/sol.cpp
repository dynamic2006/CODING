#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.in", "r", stdin);

    ll n, k, d; cin >> n >> k >> d;
    vector<ll> dpAll(n+1, 0), dpComplement(n+1, 0);
    dpAll[0] = 1; dpComplement[0] = 1;
    
    for(ll i=1; i<=n; i++){
        for(ll j=1; i-j>=0 && j<=k; j++){
            dpAll[i-j] %= MOD;
            dpAll[i] += dpAll[i-j];
            dpAll[i] %= MOD;
            if(j<d){
                dpComplement[i-j] %= MOD;
                dpComplement[i] += dpComplement[i-j];
                dpComplement[i] %= MOD;
            }
        }
    }
    // cout << "ALL " << dpAll[n] << " COMPLEMENT " << dpComplement[n] << endl;
    ll ans = dpAll[n] - dpComplement[n];
    if(ans<0) ans += MOD;
    else ans %= MOD;
    cout << ans << endl;

    // cout << "CHECK" << endl;


}