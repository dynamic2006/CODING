#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int MAXNUM = 1e5;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.in", "r", stdin);

    int n, m; cin >> n >> m;
    vector<int> colors(n+1);
    colors[0] = MAXNUM+1;
    for(int i=1; i<=n; i++) cin >> colors[i];

    // cout << "CHECK" << endl;

    vector<set<int>> connections(MAXNUM+1, set<int>());
    for(int i=0; i<m; i++){
        int a, b; cin >> a >> b;
        if(colors[a] == colors[b]) continue;
        // cout << "CHECK" << endl;
        // cout << "COLOR A " << colors[a] << " COLOR B " << colors[b] << endl;
        connections[colors[a]].insert(colors[b]);
        connections[colors[b]].insert(colors[a]);
        // cout << "CHECK" << endl;
    }

    // cout << "CHECK" << endl;

    int maxConnections = 0, ans = *min_element(colors.begin(), colors.end());
    for(int i=1; i<=MAXNUM; i++){
        if(connections[i].size() > maxConnections){
            maxConnections = connections[i].size();
            ans = i;
        }
    }
    cout << ans << endl;

}