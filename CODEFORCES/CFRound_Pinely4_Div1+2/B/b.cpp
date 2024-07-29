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
        vector<int> b(n-1);
        for(int i=0; i<n-1; i++) cin >> b[i];

        //construct array a starting from back
        vector<int> a(n, 0);
        a[n-1] = b[n-2];
        bool valid = true;
        for(int i=n-2; i>=0; i--){
            a[i] = b[i];
            a[i+1] |= a[i];
            if(i<=n-3 && ((a[i+1] & a[i+2]) != b[i+1])){
                cout << -1 << endl;
                valid = false;
                break;
            }
        }

        if(!valid) continue;

        for(int i=0; i<n; i++) cout << a[i] << " ";
        cout << endl;
    }
}