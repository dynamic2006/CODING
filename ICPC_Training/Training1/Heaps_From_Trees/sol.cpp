#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n; int ans;
vector<int> vals;
vector<vector<int>> adj;
vector<multiset<int>> lis;

int dfs(int cur)
{
    // cout << "DFSing" << endl;

    int maxSize = 0;
    int largestLIS = cur;
    for(auto &next : adj[cur]){
        int nextSize = dfs(next);
        if(nextSize > maxSize){
            maxSize = nextSize;
            largestLIS = next;
        }
    }

    if(largestLIS != cur){
        swap(lis[cur], lis[largestLIS]);
    }
    for(auto &next : adj[cur]){
        if(next == largestLIS) continue;
        lis[cur].insert(lis[next].begin(), lis[next].end());
    }

    // cout << lis->size() << endl;
    auto it = lis[cur].lower_bound(vals[cur]);
    if(it == lis[cur].end()) lis[cur].insert(vals[cur]);
    else{
        lis[cur].erase(it);
        lis[cur].insert(vals[cur]);
    }

    return lis[cur].size();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.in", "r", stdin);

    cin >> n;
    vals = vector<int>(n+1);
    adj = vector<vector<int>>(n+1, vector<int>());
    lis = vector<multiset<int>>(n+1, multiset<int>());
    for(int i=1; i<=n; i++){
        int v, p; cin >> v >> p;
        vals[i] = v;
        adj[p].push_back(i);
    }
    
    ans = dfs(1);
    cout << ans << endl;
}
//ideas
//Need to construct a sort of LIS on tree
//but across several subtrees
//dfs small-to-large with multisets + LIS fast sol
//cout size of root node multiset