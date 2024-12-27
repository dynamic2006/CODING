#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll days = 0;

void dfs(int cur, int prev, vector<vector<int>>& adj)
{
    int groupSize = adj[cur].size();
    if(groupSize == 1 && cur != 1) return;
    // if(cur != 1) groupSize--;
    int count = 0;
    if(cur != 1) groupSize--;
    days += groupSize;
    while(groupSize != 0){
        count++;
        groupSize/=2;
    }
    days += count;
    
    for(auto& next : adj[cur]){
        if(next != prev) dfs(next, cur, adj);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.in", "r", stdin);

    //greedy approach is to double until atleast enough to send off
    //then since sending another cow only adds one more in one day
    //doubling is always a better option
    
    int n; cin >> n;
    vector<vector<int>> adj(n+1, vector<int>());
    for(int i=0; i<n-1; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 0, adj);
    cout << days << endl;
}