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
        ll n, m; cin >> n >> m;
        string path; cin >> path;
        vector<vector<ll>> grid(n, vector<ll>(m));
        vector<ll> rowSums(n,0), colSums(m,0);
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin >> grid[i][j];
                rowSums[i] += grid[i][j];
                colSums[j] += grid[i][j];
            }
        }

        int r = 0, c = 0;
        for(int ch = 0; ch < path.size(); ch++){
            if(path[ch] == 'R'){
                grid[r][c] = -colSums[c];
                colSums[c] += grid[r][c];
                rowSums[r] += grid[r][c];
                c++;
            }
            else{
                grid[r][c] = -rowSums[r];
                colSums[c] += grid[r][c];
                rowSums[r] += grid[r][c];
                r++;
            }
        }
        grid[n-1][m-1] = -rowSums[n-1];

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++) cout << grid[i][j] << " ";
            cout << endl;
        }
        // cout << endl;
    }
}