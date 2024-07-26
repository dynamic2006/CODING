#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("d.in", "r", stdin);

    int t; cin >> t;
    while(t--){
        ll n, x; cin >> n >> x;
        ll ans = 0;
        for(ll a=1; a<=x-2; a++){
            for(ll b=1; b<=n/a; b++){
                ll upperBoundC = x-a-b;
                ll compare = (n-a*b)/(a+b);
                upperBoundC = min(upperBoundC, compare);
                if(upperBoundC >= 1) ans += upperBoundC;
            }
        }
        cout << ans << endl;
    }
}