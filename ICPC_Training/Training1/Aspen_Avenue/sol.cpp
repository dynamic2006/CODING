#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
double MAXNUM = 1e18;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.in", "r", stdin);

    int N, n; cin >> N; n = N/2;
    int len, wid; cin >> len >> wid;

    vector<double> pos(N+1); pos[0] = -1;
    for(int i=1; i<=N; i++) cin >> pos[i];
    sort(pos.begin(), pos.end());

    double spacing = (double)len / (n-1);
    // cout << spacing << endl;

    vector<vector<double>> ans(n+1, vector<double>(n+1, MAXNUM));
    // for(int i=0; i<=n; i++){
    //     for(int j=0; j<=n; j++){
    //         cout << ans[i][j] << " ";
    //     }
    //     cout<< endl;
    // }
    ans[0][0] = 0;
    for(int i=1; i<=N; i++){
        //first i-1 closest spots (left and right) must be filled
        //otherwise it wouldn't be optimal
        for(int l=max(0, i-n); l<=min(i, n); l++){
            int r = i-l;
            // cout << l << " " << r << endl;
            // cout << "CHECKPOINT AT " << i << " " << l << endl;
            if(l>0) ans[l][r] = min(ans[l][r], ans[l-1][r] + abs(pos[i] - spacing*(l-1)));
            // cout << "STILL GOOD" << endl;

            if(r>0){
                double leg = abs(pos[i] - spacing*(r-1));
                ans[l][r] = min(ans[l][r], ans[l][r-1] + sqrt(leg*leg + wid*wid));
            }
            // cout << "GOOD HERE TOO" << endl;
            // cout << "ans[" << l << "][" << r << "] = " << ans[l][r] << endl;
        }
    }
    // cout << "MADE IT OUT OF LOOP YAY" << endl;
    cout << fixed << setprecision(10) << ans[n][n] << endl;
}

//MAIN IDEA: TRIANGLE INEQUALITY