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
        int maxW = 0, maxH = 0;
        for(int i=0; i<n; i++){
            int w, h; cin >> w >> h;
            maxW = max(maxW, w);
            maxH = max(maxH, h);
        }

        cout << 2*(maxW + maxH) << endl;
    }
}