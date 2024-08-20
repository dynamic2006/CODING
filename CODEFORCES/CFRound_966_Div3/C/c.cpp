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
        vector<int> a(n);
        for(int i=0; i<n; i++) cin >> a[i];

        int m; cin >> m;
        vector<string> s(m);
        for(int i=0; i<m; i++) cin >> s[i];

        map<char, int> charToInt;
        map<int, char> intToChar;
        for(int i=0; i<m; i++){
            if(s[i].size() != a.size()){
                cout << "NO" << endl;
                continue;
            }

            bool valid = true;
            charToInt.clear();
            intToChar.clear();
            for(int j=0; j<s[i].size(); j++){
                if(!charToInt.count(s[i][j])){
                    charToInt[s[i][j]] = a[j];
                }
                else if(a[j] != charToInt[s[i][j]]){
                    valid = false;
                    break;
                }
                if(!intToChar.count(a[j])){
                    intToChar[a[j]] = s[i][j];
                }
                else if(s[i][j] != intToChar[a[j]]){
                    valid = false;
                    break;
                }
            }
            if(valid) cout << "YES" << endl;
            else cout << "NO" << endl;


        }
    }
}