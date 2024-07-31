#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MAXNUM = 1e18;

vector<ll> values;
vector<vector<ll>> adj;

ll dfs(ll cur)
{
    if(adj[cur].empty()) return values[cur];

    ll minSubValue = MAXNUM;
    for(auto &next : adj[cur]){
        minSubValue = min(minSubValue, dfs(next));
    }

    if(minSubValue <= values[cur]) return minSubValue;

    return (minSubValue + values[cur])/2;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("d.in", "r", stdin);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        values = vector<ll>(n);
        for(int i=0; i<n; i++) cin >> values[i];
        adj = vector<vector<ll>>(n, vector<ll>());
        for(int i=0; i<n-1; i++){
            ll parent; cin >> parent;
            adj[parent-1].push_back(i+1);
        }

        ll maxChange = MAXNUM;
        for(auto &next : adj[0]){
            maxChange = min(dfs(next), maxChange);
        }
        cout << values[0] + maxChange << endl;
    }
}