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
        int a; cin >> a;
        if(a >= 102 && a <= 109){
            cout << "YES" << endl;
            continue;
        }
        else if(a >= 1010 && a <= 1099){
            cout << "YES" << endl;
            continue;
        }
        else if(a >= 10100 && a <= 10999){
            cout << "YES" << endl;
            continue;
        }
        else cout << "NO" << endl;
    }
}