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
        int n, m; cin >> n >> m;
        vector<vector<int>> cards(n, vector<int>(m));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++) cin >> cards[i][j];
        }

        for(int i=0; i<n; i++) sort(cards[i].begin(), cards[i].end());

        bool valid = true;
        vector<int> order(n, -1);
        for(int i=0; i<n; i++){
            if(order[cards[i][0]] != -1){
                valid = false;
                break;
            }
            order[cards[i][0]] = i+1;
            for(int j=1; j<m; j++){
                if(cards[i][j] != cards[i][0] + j*n){
                    valid = false;
                    break;
                }
            }
            if(!valid) break;
        }

        if(valid) for(int i=0; i<n; i++) cout << order[i] << " ";
        else cout << -1;
        cout << endl;
    }
}