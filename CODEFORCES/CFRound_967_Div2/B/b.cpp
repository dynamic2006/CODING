#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("b.in", "r", stdin);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        if(n == 1) cout << 1 << endl;
        else if(n % 2 == 0) cout << -1 << endl;
        else{
            for(int i=1; i<=n/2; i++) cout << i << " " << n+1-i << " ";
            if(n%2 == 1) cout << (n+1)/2;
            cout << endl;
        }
    }
}