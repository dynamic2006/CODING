#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("e.in", "r", stdin);

    ll t; cin >> t;
    while(t--){
        ll n, k, q; cin >> n >> k >> q;
        vector<ll> a(k+1, 0), b(k+1, 0);
        for(ll i=1; i<=k; i++) cin >> a[i];
        for(ll i=1; i<=k; i++) cin >> b[i];

        // cout << n << " " << k << " " << q << endl;
        // for(auto &x : a) cout << x << " ";
        // cout << endl;
        // for(auto &x : b) cout << x << " ";
        // cout << endl;

        // cout << "CHECK" << endl;

        for(ll i=0; i<q; i++){
            // cout << "CHECK ";
            ll d; cin >> d;
            if(d == n){
                cout << b[k] << " ";
                continue;
            }

            // cout << "CHECK";

            ll prevSignIdx = (--upper_bound(a.begin(), a.end(), d)) - a.begin();
            ll ans = b[prevSignIdx];
            ll dist = (a[prevSignIdx+1] - a[prevSignIdx]);
            ll time = (b[prevSignIdx+1] - b[prevSignIdx]);
            ans += (d-a[prevSignIdx])*time/dist;
            cout << ans << " ";
        }
        // cout << endl;
        cout << endl;
    }
}