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
        int n; cin >> n;
        string s; cin >> s;
        map<char, int> occs;
        for(int i=0; i<n; i++){
            occs[s[i]]++;
        }

        string ans = "";
        int idx = 0;
        while(ans.size() < n){
            char c = 'a'+idx;
            if(occs[c] > 0){
                ans += c;
                occs[c]--;
            }
            idx++;
            idx %= 26;
        }
        cout << ans << endl;
    }
}