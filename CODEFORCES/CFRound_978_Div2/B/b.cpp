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
        int n, x; cin >> n >> x;
        ll tot = 0;
        ll maxNum = -1;
        for(int i=0; i<n; i++){
            ll a; cin >> a;
            tot += a;
            maxNum = max(maxNum, a);
        }

        cout << max(maxNum, (tot+(x-1))/x) << endl;

    }
}