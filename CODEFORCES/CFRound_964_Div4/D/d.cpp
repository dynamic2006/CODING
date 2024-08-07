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
        string t; cin >> t;

        int b = 0;
        for(int a=0; a<s.size(); a++){
            if(s[a] == '?' || s[a] == t[b]){
                s[a] = t[b];
                b++;
            }
            if(b == t.size()) break;
        }

        if(b == t.size()){
            cout << "YES" << endl;
            for(int i=0; i<s.size(); i++){
                if(s[i] == '?') cout << 'a';
                else cout << s[i];
            }
            cout << endl;
        }
        else cout << "NO" << endl;

    }
}