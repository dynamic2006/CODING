#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

vector<ll> val, comp, z, cont;
ll Time, ncomps;
template<class G> ll dfs(ll j, G& g) {
	ll low = val[j] = ++Time, x; z.push_back(j);
	for (auto e : g[j]) if (comp[e] < 0)
		low = min(low, val[e] ?: dfs(e,g));

	if (low == val[j]) {
		do {
			x = z.back(); z.pop_back();
			comp[x] = ncomps;
			cont.push_back(x);
		} while (x != j);
		cont.clear();
		ncomps++;
	}
	return val[j] = low;
}
template<class G> void scc(G& g) {
	ll n = sz(g);
	val.assign(n, 0); comp.assign(n, -1);
	Time = ncomps = 0;
	rep(i,0,n) if (comp[i] < 0) dfs(i, g);
}

vi topoSort(const vector<vi>& gr) {
	vi indeg(sz(gr)), q;
	for (auto& li : gr) for (int x : li) indeg[x]++;
	rep(i,0,sz(gr)) if (indeg[i] == 0) q.push_back(i);
	rep(j,0,sz(q)) for (int x : gr[q[j]])
		if (--indeg[x] == 0) q.push_back(x);
	return q;
}

void dpDFS(int cur, vector<vector<ll>>& adj, vector<ll>& dp, vector<bool>& vis)
{
    vis[cur] = true;
    ll childMax = 0;
    for(auto &next : adj[cur]){
        if(!vis[next]) dpDFS(next, adj, dp, vis);
        childMax = max(childMax, dp[next]);
    }
    dp[cur] += childMax;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.in", "r", stdin);

    ll n, m; cin >> n >> m;
    vector<vector<ll>> adj(n, vector<ll>());
    vector<ll> coins(n);
    for(ll i=0; i<n; i++) cin >> coins[i];
    for(ll i=0; i<m; i++){
        ll a, b; cin >> a >> b; a--; b--;
        adj[a].push_back(b);
    }

    scc(adj);
    vector<ll> dp(ncomps, 0);
    for(ll i=0; i<n; i++){
        // cout << i << " " << comp[i] << endl;
        dp[comp[i]] += coins[i];
    }

    vector<vector<ll>> condensed(ncomps, vector<ll>());
    for(int a=0; a<n; a++){
        for(auto b : adj[a]){
            if(comp[a] != comp[b]) condensed[comp[a]].push_back(comp[b]);
        }
    }
    
    ll maxAns = 0;
    vi ans = topoSort(condensed);
    vector<bool> vis(ncomps, false);
    for(int i=0; i<ncomps; i++){
        if(!vis[ans[i]]){
            dpDFS(ans[i], condensed, dp, vis);
        }
    }
    // cout << "HERE" << endl;
    for(int i=0; i<ncomps; i++) maxAns = max(maxAns, dp[i]);
    cout << maxAns << endl;
}