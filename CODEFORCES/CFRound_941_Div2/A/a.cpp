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
        int n, k; cin >> n >> k;
        map<int, int> occs;
        bool valid = false;
        for(int i=0; i<n; i++){
            int x; cin >> x;
            occs[x]++;
            if(occs[x] >= k) valid = true;
        }

        if(valid) cout << k-1 << endl;
        else cout << n << endl;
    }
}