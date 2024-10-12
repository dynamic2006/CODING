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
        vector<bool> hasCard(n+1, false);
        int ans = 0;
        for(int i=0; i<n; i++){
            int a; cin >> a;
            if(hasCard[a]) ans++;
            else hasCard[a] = true;
        }
        cout << ans << endl;
    }
}