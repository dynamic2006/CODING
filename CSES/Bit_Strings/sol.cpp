#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.in", "r", stdin);

    int n; cin >> n;
    int x = 1;
    for(int i=1; i<=n; i++){
        x *= 2;
        x %= MOD;
    }
    cout << x << endl;
}