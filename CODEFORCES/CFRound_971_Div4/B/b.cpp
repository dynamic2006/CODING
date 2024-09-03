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
        int n; cin >> n;
        vector<string> beats(n);
        for(int i=0; i<n; i++){
            cin >> beats[i];
        }

        for(int i=n-1; i>=0; i--){
            for(int j=0; j<4; j++){
                if(beats[i][j] == '#'){
                    cout << j+1 << " ";
                    break;
                }
            }
        }
        cout << endl;
    }
}