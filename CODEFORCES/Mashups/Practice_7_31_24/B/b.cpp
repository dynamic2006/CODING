#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MAXNUM = 1e9;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("b.in", "r", stdin);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        map<int, int> a;
        for(int i=0; i<n; i++){
            int num; cin >> num;
            a[num]++;
        }

        int m = a.size();
        vector<int> mapKeys(m+1, -1); 
        int idx = 1;
        for(auto &p : a){
            mapKeys[idx] = p.first;
            idx++;
        }

        vector<vector<int>> dp(m+1, vector<int>(m+1, MAXNUM));
        for(int i=0; i<=m; i++) dp[0][i] = 0;
        for(int i=1; i<=m; i++){
            for(int j=i; j<=m; j++){
                dp[i][j] = dp[i][j-1];
                if(dp[i-1][j-1] + a[mapKeys[j]] <= j-i){
                    dp[i][j] = min(dp[i][j], dp[i-1][j-1] + a[mapKeys[j]]);
                }
            }
        }

        for(int i=m; i>=0; i--){
            if(dp[i][m] < MAXNUM){
                cout << m-i << endl;
                break;
            }
        }

    }
}