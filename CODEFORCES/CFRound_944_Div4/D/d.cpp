#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("d.in", "r", stdin);

    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        int ans = 1;
        bool joinerUsed = false;
        for(int i=1; i<s.size(); i++){
            if(s[i-1] != s[i]){
                if(s[i-1] == '0' && s[i] == '1' && !joinerUsed) joinerUsed = true;
                else ans++;
            }
        }
        cout << ans << endl;
    }
}