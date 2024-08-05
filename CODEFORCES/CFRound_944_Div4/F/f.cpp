#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("f.in", "r", stdin);

    int t; cin >> t;
    while(t--){
        ll r; cin >> r;
        ll ans = 0;
        for(ll x=-r; x<=r; x++){
            ll loBound = sqrt(r*r - x*x);
            if(x*x + loBound*loBound < r*r) loBound++;
            ll hiBound = sqrt((r+1)*(r+1) - x*x);
            if(x*x + hiBound*hiBound >= (r+1)*(r+1)) hiBound--;
            // cout << x << " " << loBound << " " << hiBound << endl;
            if(loBound == 0) ans += (2*hiBound + 1);
            else ans += 2*(hiBound - loBound + 1);
        }
        cout << ans << endl;
    }
}