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
        for(int i=1; i<=n/2; i++){
            cout << 3*i << " " << 3*i+1 << " ";
        }
        if(n%2 != 0) cout << 3*(n/2 + 1) << endl;
        else cout << endl;
    }
}