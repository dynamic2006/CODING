#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.in", "r", stdin);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string s; cin >> s;
        bool foundOne = false;
        bool aliceWins = false;
        if(s[0] == '1' || s[n-1] == '1') aliceWins = true;
        for(int i=0; i<n; i++){
            if(s[i] == '1'){
                if(foundOne) aliceWins = true;
                else foundOne = true;
            }
            else foundOne = false;
        }
        if(aliceWins) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}