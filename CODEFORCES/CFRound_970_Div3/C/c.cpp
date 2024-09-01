#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("c.in", "r", stdin);

    int t; cin >> t;
    while(t--){
        int l, r; cin >> l >> r;
        int num = 2*(r-l);
        int k = sqrt(num);
        if(k*(k+1) <= num){
            cout << k+1 << endl;
        }
        else{
            cout << k << endl;
        }
    }
}