#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("a.in", "r", stdin);

    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        string ans = "";
        char c;
        for(int i=1; i<s.size(); i++){
            if(s[i] == s[i-1]){
                if(s[i] == 'z') c = 'a';
                else c = s[i] + 1;
                for(int j=0; j<s.size(); j++){
                    ans += s[j];
                    if(j == i-1) ans += c;
                }
                break;
            }
        }
        if(ans.size() != s.size() + 1){
            if(s[s.size()-1] == 'z') s += 'a';
            else s += (s[s.size() - 1] + 1);
            cout << s << endl;
        }
        else{
            cout << ans << endl;
        }

    }
}