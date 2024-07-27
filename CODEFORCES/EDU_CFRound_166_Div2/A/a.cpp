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
        int n; cin >> n;
        string s; cin >> s;
        int lettersBegin = -1;
        bool valid = true;
        for(int i=0; i<s.size() - 1; i++){
            if(s[i] - 'a' < 0 || s[i] - 'a' >= 26){
                lettersBegin = i; break;
            }
            else if(s[i] > s[i+1]){
                cout << "NO" << endl;
                valid = false;
                break;
            }
        }

        if(!valid) continue;
        for(int i = lettersBegin+1; i<s.size(); i++){
            if(s[i-1] > s[i]){
                cout << "NO" << endl;
                valid = false;
                break;
            }
        }
        
        if(valid) cout << "YES" << endl;
    }
}