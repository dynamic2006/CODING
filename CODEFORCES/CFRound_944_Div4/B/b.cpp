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
        string s; cin >> s;
        bool valid = false;
        for(int i=1; i<s.size(); i++){
            if(s[i] != s[i-1]){
                cout << "YES" << endl;
                for(int j=0; j<i-1; j++) cout << s[j];
                cout << s[i] << s[i-1];
                for(int j=i+1; j<s.size(); j++) cout << s[j];
                cout << endl;
                valid = true;
                break;
            }
        }
        if(!valid) cout << "NO" << endl;

    }
}