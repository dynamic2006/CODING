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
        vector<int> teacherPos(m);
        for(int i=0; i<m; i++) cin >> teacherPos[i];
        sort(teacherPos.begin(), teacherPos.end());

        for(int i=0; i<q; i++){
            int davidPos; cin >> davidPos;
            if(davidPos < teacherPos[0]){
                cout << teacherPos[0] - 1 << endl;
            }
            else if(davidPos > teacherPos[m-1]){
                cout << n - teacherPos[m-1] << endl;
            }
            else{
                auto hiBound = upper_bound(teacherPos.begin(), teacherPos.end(), davidPos);
                auto loBound = prev(hiBound);
                int ans = min(davidPos - *loBound, *hiBound - davidPos);
                ans = max(ans, (*hiBound - *loBound)/2);
                cout << ans << endl;
            }
        }
    }
}