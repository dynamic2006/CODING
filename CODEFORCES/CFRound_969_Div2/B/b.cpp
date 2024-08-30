#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("b.in", "r", stdin);

    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        vector<ll> a(n);
        ll ans = 0;
        for(int i=0; i<n; i++){
            cin >> a[i];
            ans = max(ans, a[i]);
        }

        for(int i=0; i<m; i++){
            char op; cin >> op;
            ll l, r; cin >> l >> r;
            if(ans < l || ans > r) cout << ans << " ";
            else if(op == '+') cout << ++ans << " ";
            else cout << --ans << " ";
        }
        cout << endl;
    }
}