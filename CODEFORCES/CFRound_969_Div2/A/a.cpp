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
        int l, r; cin >> l >> r;
        if(l%2 == 1) l--;
        if(r%2 == 1) r++;
        cout << (r-l)/4 << endl;
    }
}