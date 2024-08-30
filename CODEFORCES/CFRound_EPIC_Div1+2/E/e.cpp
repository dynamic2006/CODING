#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll MAXNUM = 1e18;

vector<ll> values;
vector<ll> potential;
vector<vector<ll>> adj;

ll dfs(ll cur)
{
    if(adj[cur].empty()){
        potential[cur] = MAXNUM;
        return 0;
    }

    potential[cur] = -values[cur];

    //sort out all lower nodes
    ll ops = 0;
    for(auto next : adj[cur]){
        ops += dfs(next);
        potential[cur] += values[next];
    }
    
    //fix this one if potential is negative
    ll depth = 1;
    queue<pair<ll, ll>> q;
    for(auto next : adj[cur]) q.push({next, depth});
    while(!q.empty()){
        if(potential[cur] >= 0){
            // cout << "AT VERTEX " << cur << " VALUE " << values[cur] << " OPS " << ops << endl;
            return ops;
        }
        pair<ll, ll> p = q.front(); q.pop();

        ll change = min(potential[p.first], -potential[cur]);
        // cout << change  << " " << depth << endl;
        potential[p.first] -= change;
        // cout << "POTENTIAL AT " << p.first << " CHANGED TO " << potential[p.first] << endl;
        potential[cur] += change;
        // cout << "POTENTIAL AT " << cur << " CHANGED TO " << potential[cur] << endl;
        ops += (change)*(p.second);
        // cout << "NOW OPS IS " << ops << endl;

        depth = p.second + 1;
        for(auto next : adj[p.first]){
            // cout << "NEXT " << next << " WITH DEPTH " << depth << endl;
            q.push({next, depth});
        }

    }
    // cout << "AT VERTEX " << cur << " VALUE " << values[cur] << " OPS " << ops << endl;
    return ops;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("e.in", "r", stdin);

    ll t; cin >> t;
    ll counter = 0;
    while(t--){
        counter++;
        ll n; cin >> n;
        values = vector<ll>(n+1);
        potential = vector<ll>(n+1, 0);
        adj = vector<vector<ll>>(n+1, vector<ll>());

        // if(counter == 29){
        //     cout << endl;
        //     cout << n << endl;
        //     for(ll i=1; i<=n; i++){
        //         ll x; cin >> x; cout << x;
        //     }
        //     cout << endl;
        //     for(ll i=2; i<=n; i++){
        //         ll x; cin >> x; cout << x;
        //     }
        //     cout << endl;
        //     continue;
        // }

        for(ll i=1; i<=n; i++) cin >> values[i];
        for(ll i=2; i<=n; i++){
            ll parent; cin >> parent;
            adj[parent].push_back(i);
        }

        ll ans = dfs(1);
        cout << ans << endl;

    }
}
//IDEAS
//potential list stores SUM(a_u) - a_v for each node v, children potential is +inf
//then need to make all potentials nonegative
//dfs+bfs = O(n^2), work down to up on tree, making each potential negative