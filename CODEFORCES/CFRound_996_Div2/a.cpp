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
        int n, a, b; cin >> n >> a >> b;
        int dif = abs(a-b);
        if(dif%2) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
}