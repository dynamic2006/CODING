#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("input.in", "r", stdin);

    int n, m; cin >> n >> m;
    vector<int> expected(n), actual(n);
    for(int i=0; i<n; i++) cin >> expected[i];
    for(int i=0; i<m; i++) cin >> actual[i];

    int ePtr = 0, aPtr = 0;
    
}