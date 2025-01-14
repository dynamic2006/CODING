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
        vector<int> perm(n+1);
        for(int i=1; i<=n; i++) cin >> perm[i];

        vector<bool> vis(n+1, false);

        ll ans = 0;
        int curSize = 0, start = 0;
        for(int i=1; i<=n; i++){
            if(!vis[i]){
                int ti = i;
                start = i; curSize = 1;
                while(perm[ti] != start){
                    vis[ti] = true;
                    ti = perm[ti];
                    curSize++;
                }
                vis[ti] = true;
                ans += (curSize-1)/2;
                curSize = 0;
                start = 0;
            }
        }
        cout << ans << endl;
    }
}