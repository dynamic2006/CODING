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
        int n, x; cin >> n >> x;
        vector<int> a(n), mods(n, 0);
        for(int i=0; i<n; i++){
            cin >> a[i];
        }
        sort(a.begin(), a.end());

        for(int i=0; i<n; i++){
            if(a[i] % x < n && mods[a[i]%x] >= a[i]/x) mods[a[i]%x]++;
        }

        if(x >= n){
            int i=0;
            while(i < n && mods[i] > 0) i++;
            cout << i << endl;
            continue;
        }

        int minCycles = mods[0];
        for(int i=0; i<x; i++){
            minCycles = min(minCycles, mods[i]);
        }
        int ans = minCycles*x;

        int extra = 0;
        while(mods[extra] > minCycles) extra++;
        ans += extra;
        cout << ans << endl;
    }
}