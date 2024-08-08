#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("a.in", "r", stdin);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> p(n+1);
        for(int i=1; i<=n; i++) cin >> p[i];

        int ans = -1;
        for(int i=1; i<=n; i++){
            if(p[p[i]] == i){
                ans = 2; break;
            }
        }
        if(ans == -1) ans = 3;
        cout << ans << endl;
    }
}