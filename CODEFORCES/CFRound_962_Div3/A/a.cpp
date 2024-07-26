#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("a.in", "r", stdin);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int ans = n/4;
        n -= 4*ans;
        ans += n/2;
        cout << ans << endl;
    }
}