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
        ll b, c, d; cin >> b >> c >> d;

        ll a = b ^ d;
        if((a|b) - (a&c) == d) cout << a << endl;
        else cout << -1 << endl;

    }
}