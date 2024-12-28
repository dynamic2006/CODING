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
        int n, m, q; cin >> n >> m >> q;
        vector<int> line(n);
        for(int i=0; i<n; i++) cin >> line[i];

        vector<int> slides(m);
        for(int i=0; i<m; i++) cin >> slides[i];

        vector<bool> seen(n+1, false);
        seen[0] = true;

        vector<int> condensed;
        for(int i=0; i<m; i++){
            if(!seen[slides[i]]){
                condensed.push_back(slides[i]);
                seen[slides[i]] = true;
            }
        }

        bool valid = true;
        int k = condensed.size();
        for(int i=0; i<min(n, k); i++){
            if(condensed[i] != line[i]) valid = false;
        }

        if(valid) cout << "YA" << endl;
        else cout << "TIDAK" << endl;
    }
}