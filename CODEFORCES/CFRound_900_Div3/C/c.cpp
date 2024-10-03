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
        ll n, k, x; cin >> n >> k >> x;
        ll loBound = (k*(k+1))/2;
        ll hiBound = ((n+n-k+1)*(k))/2;
        if(x>=loBound && x<=hiBound){
            cout << "YES" << endl;
        }
        else cout << "NO" << endl;
    }
}