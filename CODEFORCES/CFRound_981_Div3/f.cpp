#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll MOD = 1e9+7;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.in", "r", stdin);

    int t; cin >> t;
    while(t--){
        ll n, k; cin >> n >> k;
        ll a=1, b=1, cyclelen = 2;

        if(k == 1){
            cout << (n % MOD) << endl;
            continue;
        }

        while(b){
            ll tmp = a;
            a = b;
            b += tmp;
            b %= k;
            cyclelen++;
            cyclelen %= MOD;
        }

        cyclelen %= MOD;
        n %= MOD;
        ll ans = (n * cyclelen);
        ans %= MOD;

        cout << ans << endl;
    }
}