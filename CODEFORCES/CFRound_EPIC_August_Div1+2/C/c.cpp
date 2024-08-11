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
        int n; cin >> n;
        vector<pair<ll, ll>> centers(n);
        pair<ll, ll> start, end;

        for(int i=0; i<n; i++) cin >> centers[i].first >> centers[i].second;
        cin >> start.first >> start.second;
        cin >> end.first >> end.second;

        ll dist = (start.first - end.first)*(start.first - end.first) + (start.second - end.second)*(start.second - end.second);

        bool valid = true;
        for(int i=0; i<n; i++){
            // cout << "P1 " << pow((centers[i].first - end.first),2) << " " << pow((centers[i].second - end.second), 2) << endl;
            ll curDist = (centers[i].first - end.first)*(centers[i].first - end.first) + (centers[i].second - end.second)*(centers[i].second - end.second);
            if(curDist <= dist){
                // cout << dist << " " << curDist << endl;
                valid = false; break;
            }
        }

        if(valid) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}