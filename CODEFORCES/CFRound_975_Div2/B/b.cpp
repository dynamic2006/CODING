#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.in", "r", stdin);

    ll t; cin >> t;
    while(t--){
        ll n, q; cin >> n >> q;
        vector<ll> x(n);
        for(ll i=0; i<n; i++) cin >> x[i];

        map<ll, ll> kOccs; //first is k value, second is # of pts
        for(ll i=1; i<n; i++){
            ll segs = (i)*(n-i);
            kOccs[segs] += x[i] - x[i-1] - 1;
            kOccs[segs+i-1]++;
        }
        kOccs[n-1]++;

        for(ll i=0; i<q; i++){
            ll kq; cin >> kq;
            cout << kOccs[kq] << " ";
        }
        cout << endl;

    }
}