#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.in", "r", stdin);

    ll n; cin >> n;
    ll factor = 5;

    ll ans = 0;
    while(factor <= n){
        ans += (n/factor);
        factor *= 5;
    }

    cout << ans << endl;
}