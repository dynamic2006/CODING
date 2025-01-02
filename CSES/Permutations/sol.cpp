#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.in", "r", stdin);

    int n; cin >> n;

    if(n <= 3){
        if(n == 1) cout << 1 << endl;
        else cout << "NO SOLUTION" << endl;
        return 0;
    }

    for(int i=2; i<=n; i+=2) cout << i << " ";
    for(int i=1; i<=n; i+=2) cout << i << " ";
    cout << endl;
}