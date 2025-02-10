#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.in", "r", stdin);

    ll n, p, x, y; cin >> n >> p >> x >> y;
    ll ans = x*p;
    ll k = p/(n-1);
    ans += y*k;
    cout << ans << endl;
}