#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("e.in", "r", stdin);

    int t; cin >> t;
    while(t--){
        ll n, m, k; cin >> n >> m >> k;
        ll w; cin >> w;
        vector<ll> a(w);
        for(ll i=0; i<w; i++) cin >> a[i];
        sort(a.begin(), a.end(), greater<ll>());

        // for(auto x : a){
        //     cout << x << " ";
        // }
        // cout << endl;

        vector<ll> occs;
        for(ll i=0; i<n; i++){
            for(ll j=0; j<m; j++){
                ll x, y;
                ll lox, hix, loy, hiy;
                lox = max((ll)0, j-(k-1));
                hix = min(m-k, j);
                loy = max((ll)0, i-(k-1));
                hiy = min(n-k, i);
                x = hix - lox + 1;
                y = hiy - loy + 1;
                occs.push_back(x*y);
            }
        }
        sort(occs.begin(), occs.end(), greater<ll>());

        // for(auto x : occs){
        //     cout << x << " ";
        // }
        // cout << endl;

        ll ans = 0;
        for(ll i=0; i<w; i++){
            ans += a[i]*occs[i];
        }
        cout << ans << endl;

    }
}