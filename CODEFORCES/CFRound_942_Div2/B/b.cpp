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
        string s; cin >> s;
        int uCount = 0;
        for(int i=0; i<n; i++){
            if(s[i] == 'U') uCount++;
        }
        if(uCount % 2 == 0) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
}