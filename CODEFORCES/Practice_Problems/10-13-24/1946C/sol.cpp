#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, k;
int groupSize, groupCount;
vector<vector<int>> adj;

int dfs(int cur, int prev)
{
    int size = 1;
    for(auto &next : adj[cur]){
        if(next != prev){
            size += dfs(next, cur);
        }
    }

    if(size >= groupSize){
        groupCount++;
        return 0;
    }
    else return size;
}

bool valid(int gs)
{
    groupSize = gs;
    groupCount = 0;
    dfs(1, 0);
    if(groupCount >= k+1) return true;
    return false;
}

int binarySearch(int lo, int hi)
{
    lo--;
    while(lo<hi){
        int mid = lo + (hi-lo+1)/2;
        if(valid(mid)) lo = mid;
        else hi = mid-1;
    }
    return lo;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.in", "r", stdin);

    int t; cin >> t;
    while(t--){
        adj.clear();
        cin >> n >> k;
        adj = vector<vector<int>>(n+1, vector<int>());
        for(int i=1; i<n; i++){
            int a, b; cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        int ans = binarySearch(1, n);
        cout << ans << endl;
    }
}