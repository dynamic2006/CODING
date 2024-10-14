#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.in", "r", stdin);

    int n; cin >> n;
    int ans = 0;
    for(int i=0; i<n; i++){
        int diff; cin >> diff;
        if(diff % 2 == 1) ans++;
    }
    cout << ans << endl;
}