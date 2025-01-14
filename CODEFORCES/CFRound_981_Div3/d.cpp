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
        vector<int> a(n);
        for(int i=0; i<n; i++) cin >> a[i];

        vector<ll> prefixSum(n, 0); prefixSum[0] = a[0];
        for(int i=1; i<n; i++) prefixSum[i] = prefixSum[i-1] + a[i];

        int ans = 0;
        set<ll> seen; seen.insert(0);
        for(int i=0; i<n; i++){
            if(seen.count(prefixSum[i])){
                ans++; seen.clear();
            }
            seen.insert(prefixSum[i]);
        }
        cout << ans << endl;
    }
}