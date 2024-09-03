#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("d.in", "r", stdin);

    int t; cin >> t;
    while(t--){
        ll n; cin >> n;
        vector<vector<bool>> points(2, vector<bool>(n+1, false));
        ll bottomPoints = 0, topPoints = 0;
        for(ll i=0; i<n; i++){
            ll x, y; cin >> x >> y;
            points[y][x] = true;
            if(y == 0) bottomPoints++;
            else topPoints++;
        }

        ll ans = 0;
        for(int i=0; i<=n; i++){
            if(points[0][i] && points[1][i]){
                ans += (bottomPoints + topPoints - 2);
            }
        }

        for(int i=1; i<n; i++){
            if(points[0][i] && points[1][i-1] && points[1][i+1]) ans++;
            if(points[1][i] && points[0][i-1] && points[0][i+1]) ans++;
        }

        cout << ans << endl;
    }
}