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
        int n; cin >> n;
        int x, y; cin >> x >> y;
        int xVal = (n+x-1)/x;
        int yVal = (n+y-1)/y;
        cout << max(xVal, yVal) << endl;
    }
}