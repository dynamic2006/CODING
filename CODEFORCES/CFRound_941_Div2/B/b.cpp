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
        int n, m; cin >> n >> m;
        bool whiteRight = false, whiteTop = false, whiteBot = false, whiteLeft = false;
        bool blackRight = false, blackTop = false, blackBot = false, blackLeft = false;
        for(int i=0; i<n; i++){
            string s; cin >> s;
            if(i == 0){
                for(int j=0; j<m; j++){
                    if(s[j] == 'W') whiteTop = true;
                    else blackTop = true;
                }
            }

            if(s[0] == 'W') whiteLeft = true;
            else blackLeft = true;

            if(s[m-1] == 'W') whiteRight = true;
            else blackRight = true;

            if(i == n-1){
                for(int j=0; j<m; j++){
                    if(s[j] == 'W') whiteBot = true;
                    else blackBot = true;
                }
            }
        }

        if(whiteTop && whiteBot && whiteLeft && whiteRight ||
        blackTop && blackBot && blackLeft && blackRight){
            cout << "YES" << endl;
        }
        else cout << "NO" << endl;
    }
}