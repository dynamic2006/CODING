#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("d1.in", "r", stdin);

    int t; cin >> t;
    while(t--){
        ll n, m; cin >> n >> m;
        ll ans = n;
        for(ll b=2; b<=m; b++){
            ll a = n/b;
            ans += (a+1)/b;
        }
        cout << ans << endl;
    }
}