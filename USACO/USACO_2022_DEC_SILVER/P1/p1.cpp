#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 200005;

struct Order {
    int from, to;
    ll amount;
};

ll haybales[MAXN];
ll subtreeSums[MAXN];
vector<vector<int>> adj;
vector<Order> orders;

ll dfsTreeSums(int cur, int prev){
    ll curSum = haybales[cur];
    for(int next : adj[cur]){
        if(next != prev) curSum += dfsTreeSums(next, cur);
    }
    subtreeSums[cur] = curSum;
    return curSum;
}

void dfsOrd(int cur, int prev){
    //step 1: dfs over all positive subtree nodes
    for(int next : adj[cur]){
        if(next != prev && subtreeSums[next] > 0) dfsOrd(next, cur);
    }

    //step 2: dfs over all neutral/negative subtrees, giving them hay in the process
    for(auto next : adj[cur]){
        if(next != prev && subtreeSums[next] <= 0){
            if(subtreeSums[next] < 0){
                //give hay to the subtree
                orders.push_back({cur, next, -subtreeSums[next]});
            }
            dfsOrd(next, cur);
        }
    }

    //step 3: give the parent extra hay
    if(cur != 1 && subtreeSums[cur] > 0){
        orders.push_back({cur, prev, subtreeSums[cur]});
    }
}

int main(){
    //freopen("p1.in" , "r" , stdin);

    int n; cin >> n;
    ll hayBaleSum = 0;
    for(int i=1; i<=n; i++){
        cin >> haybales[i];
        hayBaleSum += haybales[i];
    }

    //normalize
    ll goal = hayBaleSum / n;
    for(int i=1; i<=n; i++) haybales[i] -= goal;

    adj.resize(n+1);
    for(int i=0; i<n-1; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfsTreeSums(1,0);

    dfsOrd(1,1);

    cout << orders.size() << endl;
    for(auto x : orders){
        cout << x.from << " " << x.to << " " << x.amount << endl;
    }
    return 0;

}