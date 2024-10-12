#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MAXNUM = 500;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<ll> ans(MAXNUM+1); ans[0] = 0;
    for(int i=1; i<=MAXNUM; i++){
        ans[i] = ans[i-1] + i*(2*i-1);
    }

    // freopen("input.in", "r", stdin);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        
        cout << ans[n] << " " << 2*n << endl;
        for(int i=1; i<=n; i++){
            cout << 1 << " " << n-i+1 << " ";
            for(int j=n; j>=1; j--) cout << j << " ";
            cout << endl;
            cout << 2 << " " << i << " ";
            for(int j=1; j<=n; j++) cout << j << " ";
            cout << endl;
        }

    }

}