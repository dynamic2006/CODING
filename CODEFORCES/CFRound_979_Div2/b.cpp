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
        if(n>1) cout << 1;
        else cout << 0;
        for(int i=0; i<n-1; i++) cout << 0;
        cout << endl;
    }
}