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
        vector<int> a(n);
        for(int i=0; i<n; i++){
            cin >> a[i];
        }

        int gold = 0;
        int ans = 0;
        for(int i=0; i<n; i++){
            if(a[i] >= k) gold += a[i];
            else if (a[i] == 0 && gold > 0){
                ans++; gold--;
            }
        }
        cout << ans << endl;
    }
}