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
        int n, k; cin >> n >> k;
        k %= 4;
        if(k == 0) cout << "YES" << endl;
        else if (k == 1){
            if(n%2 == 0) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
        else if(k == 2) cout << "NO" << endl;
        else{
            if(n%2 == 1) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
}