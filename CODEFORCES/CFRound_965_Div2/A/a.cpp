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
        int xc, yc, k; cin >> xc >> yc >> k;
        for(int i=1; i<=k/2; i++){
            cout << xc - i << " " << yc - i << endl;
            cout << xc + i << " " << yc + i << endl;
        }
        if(k%2 == 1) cout << xc << " " << yc << endl;
    }
}