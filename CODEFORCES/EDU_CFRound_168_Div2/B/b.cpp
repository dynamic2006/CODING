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
        int n; cin >> n;
        int ans = 0;
        string r1, r2; cin >> r1 >> r2;
        for(int i=1; i<n-1; i++){
            if(r1[i] == '.' && r1[i-1] == '.' && r1[i+1] == '.'){
                if(r2[i-1] == 'x' && r2[i] == '.' && r2[i+1] == 'x') ans++;
            }
            if(r2[i] == '.' && r2[i-1] == '.' && r2[i+1] == '.'){
                if(r1[i-1] == 'x' && r1[i] == '.' && r1[i+1] == 'x') ans++;
            }
        }
        cout << ans << endl;
    }
}