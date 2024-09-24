#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.in", "r", stdin);

    int t; cin >> t;
    while(t--){
        ll n; cin >> n;
        vector<double> a(n);
        for(ll i=0; i<n; i++) cin >> a[i];
        sort(a.begin(), a.end());
        
        if(n < 3){
            cout << -1 << endl;
            continue;
        }

        double thresh = a[n/2];
        double amt = 2*thresh*n;
        for(ll i=0; i<n; i++){
            amt -= a[i];
        }

        // cout << amt << endl;
        if(amt < 0) cout << 0 << endl;
        else cout << (ll) (amt+1) << endl;


    }
}