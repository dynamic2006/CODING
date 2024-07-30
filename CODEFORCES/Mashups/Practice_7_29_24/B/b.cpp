#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("b.in", "r", stdin);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        ll ans = 0, total = 0;
        for(int x=2; x<=n; x++){
            ll k = n/x;
            if(((k*(k+1))/2)*x > total){
                ans = x;
                total = ((k*(k+1))/2)*x;
            }
        }

        cout << ans << endl;
    }
}