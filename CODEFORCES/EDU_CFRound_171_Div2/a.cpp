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
        int x, y, k; cin >> x >> y >> k;
        int a = min(x,y);
        int diff = max(0, k*k - a*a);
        int b = (int) sqrt(diff); b++;

        cout << 0 << " " << 0 << " " << a << " " << b << endl;
        cout << b << " " << 0 << " " << 0 << " " << a << endl;
    }
}