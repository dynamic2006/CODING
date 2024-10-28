#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.in", "r", stdin);

    int n, m; cin >> n >> m;
    vector<double> p(n+m+1);
    for(int i=1; i<=n+m; i++) cin >> p[i];

    double ans = 0;
    double curProb = 1;
    // cout << "CHEKC" << endl;

    vector<vector<double>> probStates(n+1, vector<double>(m+1, 0));
    probStates[n][m] = 1;

    for(int i=n; i>=0; i--){
        for(int j=m; j>=0; j--){
            if(i<n && j!=0) probStates[i][j] += (1-p[n+m-i-j])*(probStates[i+1][j]);
            if(j<m && i!=0) probStates[i][j] += (p[n+m-i-j])*(probStates[i][j+1]);
        }
    }
    // cout << "CHECK" << endl;

    for(int i=n; i>=1; i--){
        // cout << "IN LOOP" << endl;
        ans += probStates[i][0];
        // cout << probStates[i][0] << " ";
        // if(probStates[i][0] == 1) break;
    }
    // cout << endl;
    cout << fixed << setprecision(10) << ans << endl;
}