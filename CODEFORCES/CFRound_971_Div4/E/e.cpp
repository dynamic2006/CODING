#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll MAXNUM = 9*1e18;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("e.in", "r", stdin);

    int t; cin >> t;
    while(t--){
        ll n, k; cin >> n >> k;

        ll sum = ((2*k + n - 1)*(n))/2;
        // cout << "SUM " << sum << endl;

        ll lox = 1, hix = n;
        while(lox < hix){
            ll midx = lox + (hix - lox + 1)/2;
            if((2*k+midx-1)*(midx) <= sum) lox = midx;
            else hix = midx-1;
        }

        ll ans = abs(((2*k+lox-1)*(lox))/2 - ((2*k+n+lox-1)*(n-lox))/2);
        lox++;
        ans = min(ans, abs(((2*k+lox-1)*(lox))/2 - ((2*k+n+lox-1)*(n-lox))/2));
        cout << ans << endl;
    }
}