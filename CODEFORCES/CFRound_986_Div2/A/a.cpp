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
        bool found = false;
        int n, a, b; cin >> n >> a >> b;
        string s; cin >> s;

        map<char, pair<int, int>> dir;
        dir['N'] = {0, 1};
        dir['S'] = {0, -1};
        dir['E'] = {1, 0};
        dir['W'] = {-1, 0};

        pair<int, int> start = {0,0};
        for(int i=0; i<n; i++){
            start.first += dir[s[i]].first;
            start.second += dir[s[i]].second;
            // cout << start.first << " " << start.second << endl;
            if(start.first == a && start.second == b){
                cout << "YES" << endl;
                found = true;
                break;
            }
        }
        if(found) continue;

        if(start.first == 0 && start.second == 0){
            cout << "NO" << endl;
            continue;
        }

        for(int j=0; j<100; j++){
            for(int i=0; i<n; i++){
                start.first += dir[s[i]].first;
                start.second += dir[s[i]].second;
                if(start.first == a && start.second == b){
                    cout << "YES" << endl;
                    found = true;
                    break;
                }
            }
            if(found) break;
        }
        if(found) continue;
        cout << "NO" << endl;
    }
}