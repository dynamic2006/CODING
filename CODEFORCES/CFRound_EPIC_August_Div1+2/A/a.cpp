#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("a.in", "r", stdin);

    int t; cin >> t;
    while(t--){
        ll n, m, k; cin >> n >> m >> k;
        ll ans = min(k, n) * min(k, m);
        cout << ans << endl;
    }
}