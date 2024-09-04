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
        int a, b, c; cin >> a >> b >> c;
        if(c != a+1){
            cout << -1 << endl;
            continue;
        }

        int height = 0;
        int power2 = 1;
        while(power2 <= a){
            power2 *= 2;
            height++;
        }
        
        b -= power2 - (a+1);
        if(b <= 0) cout << height << endl;
        else cout << height + (b+a)/(a+1) << endl;
    }
}