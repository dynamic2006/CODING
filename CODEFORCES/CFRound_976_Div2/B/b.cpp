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
        ll k; cin >> k;
        ll x = sqrt(k);
        if(x+k < (x+1)*(x+1)) cout << x + k << endl;
        else cout << x + k + 1 << endl;
    }
}