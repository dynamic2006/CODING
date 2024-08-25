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
        int n; cin >> n;
        string s; cin >> s;
        if(s[0] == s[s.size()-1]){
            cout << "NO" << endl;
        }
        else cout << "YES" << endl;
    }
}