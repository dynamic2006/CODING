#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll MAXNUM = 1e18;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("c.in", "r", stdin);

    int t; cin >> t;
    while(t--){
        ll n, k; cin >> n >> k;
        vector<ll> a(n);
        for(int i=0; i<n; i++) cin >> a[i];
        sort(a.begin(), a.end());

        bool valid = true;
        ll lo = a[n-1], hi = a[n-1] + k - 1;
        for(int i=n-2; i>=0; i--){
            ll diff = (a[n-1] - a[i])/k;
            if(diff%2 == 1) diff++;
            lo = max(lo, a[i] + k*diff);
            hi = min(hi, a[i] + k*(diff+1) - 1);

            if(lo > hi){
                valid = false;
                break;
            }
        }

        if(valid) cout << lo << endl;
        else cout << -1 << endl;

    }
}