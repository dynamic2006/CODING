#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("a.in", "r", stdin);

    int t; cin >> t; 
    while(t--){
        int n; cin >> n;
        vector<int> a(n), b(n);
        for(int i=0; i<n; i++) cin >> a[i];
        for(int i=0; i<n; i++) cin >> b[i];

        int maxMoves = 0;
        for(int i=0; i<n-maxMoves; i++){
            int dist = lower_bound(b.begin(), b.end(), a[i]) - b.begin() - i;
            // cout << dist << " ";
            maxMoves = max(maxMoves, dist);
        }
        // cout << endl;
        cout << maxMoves << endl;
    }
}