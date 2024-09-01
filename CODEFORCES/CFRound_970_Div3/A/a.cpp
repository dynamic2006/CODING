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
        int a, b; cin >> a >> b;
        if(a%2 == 1){
            cout << "NO" << endl;
            continue;
        }
        if(b%2 == 1 && a<2){
            cout << "NO" << endl;
            continue;
        }
        else cout << "YES" << endl;
    }
}