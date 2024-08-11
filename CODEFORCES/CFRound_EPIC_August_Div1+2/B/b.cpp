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
        vector<int> a(n), b(n);
        bool bobWins = true;
        for(int i=0; i<n; i++) cin >> a[i];
        for(int i=0; i<n; i++){
            cin >> b[i];
            if(b[i] != a[i]) bobWins = false;
        }
        
        if(bobWins){
            cout << "Bob" << endl;
            continue;
        }

        bobWins = true;
        for(int i=0; i<n; i++){
            if(a[i] != b[n-1-i]) bobWins = false;
        }

        if(bobWins){
            cout << "Bob" << endl;
            continue;
        }
        else cout << "Alice" << endl;

    }
} 