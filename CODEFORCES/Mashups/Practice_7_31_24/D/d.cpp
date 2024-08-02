#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MAXNUM = 1e6 + 1;

int n, m;
int maxR, minR, maxC, minC;
vector<int> rowAnsChanges, colAnsChanges;
vector<int> extraRow, extraCol;
vector<vector<bool>> vis;
// vector<int> amts;

int dfs(int i, int j, int color)
{
    minR = min(i, minR); maxR = max(i, maxR);
    minC = min(j, minC); maxC = max(j, maxC);
    
    vis[i][j] = true;
    int total = 1;
    if(i+1 < n && !vis[i+1][j]) total += dfs(i+1, j, color);
    if(i-1 >= 0 && !vis[i-1][j]) total += dfs(i-1, j, color);
    if(j+1 < m && !vis[i][j+1]) total += dfs(i, j+1, color);
    if(j-1 >=0 && !vis[i][j-1]) total += dfs(i, j-1, color);

    return total;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("d.in", "r", stdin);

    int t; cin >> t;
    while(t--){
        cin >> n >> m;
        vector<string> grid(n);
        for(int i=0; i<n; i++) cin >> grid[i];
        
        extraRow = vector<int>(n, 0);
        extraCol = vector<int>(m, 0);
        rowAnsChanges = vector<int>(n+1, 0);
        colAnsChanges = vector<int>(m+1, 0);
        vis = vector<vector<bool>>(n, vector<bool>(m, false));
        // amts = vector<int>(MAXNUM, 0);

        // cout << "CHECK" << endl;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == '.') vis[i][j] = true;
            }
        }

        // cout << "CHECK" << endl;
        
        int color = 1;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == '.'){
                    extraRow[i]++;
                    extraCol[j]++;
                }
                if(!vis[i][j]){
                    maxR = i; minR = i;
                    maxC = j; minC = j;
                    int totalSize = dfs(i, j, color);

                    rowAnsChanges[max(0, minR-1)] += totalSize;
                    rowAnsChanges[min(n, maxR+2)] -= totalSize;
                    colAnsChanges[max(0, minC-1)] += totalSize;
                    colAnsChanges[min(m, maxC+2)] -= totalSize;
                    color++;
                }
            }
        }

        int ans = 0;

        int prefixRowAns = 0;
        for(int i=0; i<n; i++){
            prefixRowAns += rowAnsChanges[i];
            ans = max(ans, extraRow[i] + prefixRowAns);
            // cout << curRowTotal + prefixRowAns << " ";
        }
        // cout << endl;
        int prefixColAns = 0;
        for(int j=0; j<m; j++){
            prefixColAns += colAnsChanges[j];
            ans = max(ans, extraCol[j] + prefixColAns);
            // cout << curColTotal + prefixColAns << " ";
        }
        // cout << endl;
        
        cout << ans << endl;

    }
}