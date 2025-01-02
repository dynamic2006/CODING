#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.in", "r", stdin);

    int n, x; cin >> n;
    x = 0;

    for(int i=1; i<=n; i++) x^=i;
    for(int i=0; i<n-1; i++){
        int a; cin >> a;
        x^=a;
    }
    cout << x << endl;
}