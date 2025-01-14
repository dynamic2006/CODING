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
        vector<vector<int>> grid(n, vector<int>(n));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++) cin >> grid[i][j];
        }

        int ans = 0;
        int curMin = 0;
        for(int i=n-1; i>0; i--){
            int j=0, tempi = i;
            curMin = 0;
            while(tempi < n && j < n){
                curMin = min(curMin, grid[tempi][j]);
                tempi++; j++;
            }
            ans += curMin;
        }

        curMin = 0;
        for(int i=0; i<n; i++){
            curMin = min(curMin, grid[i][i]);
        }
        ans += curMin;

        for(int j=n-1; j>0; j--){
            int i=0, tempj = j;
            curMin = 0;
            while(tempj<n && i<n){
                curMin = min(curMin, grid[i][tempj]);
                tempj++; i++;
            }
            ans += curMin;
        }

        cout << -ans << endl;
    }
}