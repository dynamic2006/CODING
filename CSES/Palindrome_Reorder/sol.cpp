#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.in", "r", stdin);

    string s; cin >> s;
    int alpha[26] = {};
    for(int i=0; i<s.size(); i++){
        alpha[s[i] - 'A']++;
    }

    bool foundOdd = false;
    int oddIdx = -1;
    for(int i=0; i<26; i++){
        if(alpha[i]%2){
            if(foundOdd){
                cout << "NO SOLUTION" << endl;
                return 0;
            }
            else foundOdd = true;
            oddIdx = i;
        }
    }
    
    string pal = "";
    for(int i=0; i<26; i++){
        for(int j=0; j<(alpha[i]/2); j++) pal += ('A' + i);
    }

    if(oddIdx >= 0) pal += ('A' + oddIdx);

    for(int i=25; i>=0; i--){
        for(int j=0; j<alpha[i]/2; j++) pal += ('A' + i);
    }

    cout << pal << endl;

}