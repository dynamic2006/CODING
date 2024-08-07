#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("c.in", "r", stdin);

    int t; cin >> t;
    while(t--){
        int n, s, m; cin >> n >> s >> m;
        vector<pair<int, int>> tasks(n);
        for(int i=0; i<n; i++) cin >> tasks[i].first >> tasks[i].second;

        int prevTime = 0;
        bool valid = false;
        for(auto &p : tasks){
            if(p.first - prevTime >= s){
                valid = true; break;
            }
            prevTime = p.second;
        }
        if(m - prevTime >= s) valid = true;

        if(valid) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}