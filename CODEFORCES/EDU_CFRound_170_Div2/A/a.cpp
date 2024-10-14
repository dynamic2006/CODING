#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.in", "r", stdin);

    int q; cin >> q;
    while(q--){
        string s, t; cin >> s >> t;
        int idx = 0;
        while(idx < min(s.size(), t.size()) && s[idx] == t[idx]) idx++;
        int ans = s.size() + t.size() - idx + 1;
        if(idx == 0) ans--;
        cout << ans << endl;
    }
}