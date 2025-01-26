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
        int n, m; cin >> n >> m;
        vector<int> a(n);
        int evenCount = 0;
        for(int i=0; i<n; i++){
            int ai; cin >> ai; ai%=m;
            if(ai < abs(ai-m)) a[i] = ai;
            else if(ai > abs(ai-m)) a[i] = ai-m;
            else evenCount++;
        }
        sort(a.begin(), a.end());
        
        ll ans = 0;
        int idx = a.size()/2;
        for(int i=0; i<a.size(); i++){
            ans += abs(a[i] - a[idx]);
        }
        ans += (evenCount)*(m/2 - abs(a[idx]));
        cout << ans << endl;
        // else{
        //     ll ans = 0;
        //     int idx = a.size()/2;
        //     for(int i=0; i<a.size(); i++){
        //         ans += abs(a[i] - a[idx]);
        //     }
        //     ans += (evenCount)*(m/2 - abs(a[idx]));

        //     ll otherAns = 0; idx--;
        //     for(int i=0; i<a.size(); i++){
        //         ans += abs(a[i] - a[idx]);
        //     }
        //     otherAns += (evenCount)*(m/2 - abs(a[idx]));

        //     cout << min(ans, otherAns) << endl;
        // }
    }
}