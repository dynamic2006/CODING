#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("b.in", "r", stdin);

    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        string s;
        for(int i=0; i<n; i++){
            cin >> s;
            if(i%k != 0) continue;
            for(int j=0; j<n; j+=k){
                cout << s[j];
            }
            cout << endl;
        }
        //cout << endl;
    }
}