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
        ll a, b; cin >> a >> b;
        if((a+b)%3 || abs(a-b) > min(a,b)){
            cout << "NO" << endl;
        }
        else cout << "YES" << endl;
    }
}