#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct Edge
{
	int from, to;
	int weight;
};

vi val, comp, z, cont;
int Time, ncomps;
template<class G> int dfs(int j, G& g) {
	int low = val[j] = ++Time, x; z.push_back(j);
	for (auto e : g[j]) if (comp[e.first] < 0)
		low = min(low, val[e.first] ?: dfs(e.first,g));

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
	int n = sz(g);
	val.assign(n, 0); comp.assign(n, -1);
	Time = ncomps = 0;
	rep(i,0,n) if (comp[i] < 0) dfs(i, g);
}

vi topoSort(const vector<vector<pair<int, int>>>& gr) {
	vi indeg(sz(gr)), q;
	for (auto& li : gr) for (pii x : li) indeg[x.first]++;
	rep(i,0,sz(gr)) if (indeg[i] == 0) q.push_back(i);
	rep(j,0,sz(q)) for (pii x : gr[q[j]])
		if (--indeg[x.first] == 0) q.push_back(x.first);
	return q;
}

int pathDFS(int cur, int curLen, vector<bool>& vis, vector<vector<pair<int, int>>>& compressed)
{
	int maxPathLen = curLen;
	// cout << "AT " << cur << " STARTING WITH MAXLEN " << maxPathLen << endl;
	vis[cur] = true;
	for(auto& next : compressed[cur]){
		maxPathLen = max(maxPathLen, pathDFS(next.first, curLen + next.second, vis, compressed));
	}
	// cout << "AT " << cur << " FOUND MAXLEN OF " << maxPathLen << endl;
	return maxPathLen;
}

map<string, int> idx;

int main()
{
	// freopen("input.in" , "r" , stdin);

	int m, n; cin >> m >> n;
	vector<Edge> edges;

	//process edges
	int counter = 0;
	for(int i=0; i<m; i++){
		string x, y; cin >> x >> y;
		if(!idx.count(x)) idx[x] = counter++;
		if(!idx.count(y)) idx[y] = counter++;
		Edge k; k.from = idx[x]; k.to = idx[y]; k.weight = 0;
		edges.push_back(k);
	}
	for(int i=0; i<n; i++){
		string x, y; cin >> x >> y;
		if(!idx.count(x)) idx[x] = counter++;
		if(!idx.count(y)) idx[y] = counter++;
		Edge k; k.from = idx[x]; k.to = idx[y]; k.weight = 1;
		edges.push_back(k);
	}

	// cout << "COUNTER " << counter << endl;

	//build actual adj
	vector<vector<pair<int,int>>> adj(counter, vector<pair<int,int>>());
	for(int i=0; i<n+m; i++){
		adj[edges[i].from].push_back({edges[i].to, edges[i].weight});
	}

	// for(auto& i : adj){
	// 	for(auto& j : i){
	// 		cout << j.first << "|" << j.second << " ";
	// 	}
	// 	cout << endl;
	// }
	// cout << endl;
	// cout << endl;

	scc(adj);

	// for(auto& i : adj){
	// 	for(auto& j : i){
	// 		cout << j.first << "|" << j.second << " ";
	// 	}
	// 	cout << endl;
	// }

	// for(auto p : idx){
	// 	cout << p.first << " " << p.second << endl;
	// }
	// cout << endl;

	// for(int i=0; i<m+n; i++){
	// 	cout << i << " " << comp[i] << endl;
	// }
	// cout << "OKAY" << endl;

	vector<vector<pair<int, int>>> compressed(ncomps, vector<pair<int, int>>());
	
	for(int i=0; i<counter; i++){
		for(auto& j : adj[i]){
			if(comp[i] != comp[j.first]){
				compressed[comp[i]].push_back({comp[j.first], j.second});
			}
		}
	}

	// for(auto& i : compressed){
	// 	for(auto& j : i){
	// 		cout << j.first << "|" << j.second << " ";
	// 	}
	// 	cout << endl;
	// }

	int maxAns = ncomps;

	//weighted 0/1 dfs to find max len path for each dag, sum to get final minAns
	vector<int> order = topoSort(compressed);
	vector<bool> vis(ncomps, false);
	int minAns = 0;
	for(int i=0; i<order.size(); i++){
		if(!vis[order[i]]){
			// cout << "Starting path from " << order[i] << endl;
			minAns = max(minAns, pathDFS(order[i], 1, vis, compressed));
		}
	}
	cout << minAns << " " << maxAns << endl;
}