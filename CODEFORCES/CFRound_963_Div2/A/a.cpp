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
        vector<int> counts(4);
        for(int i=0; i<s.size(); i++){
            if(s[i] != '?') counts[s[i] - 'A']++;
        }

        int ans = 0;
        for(int i=0; i<4; i++){
            ans += min(n, counts[i]);
        }
        cout << ans << endl;

    }
}