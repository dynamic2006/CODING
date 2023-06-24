#include <bits/stdc++.h>
using namespace std;

const long long MAXN = 2*1e5;

long long longestPathToLeaf[MAXN+1], maxPathToLeaf[MAXN+1];
map<long long, vector<long long>> adj;

void dfs(long long curNode, long long prevNode){

    long long firstLongest = 0, secondLongest = 0;

    for(auto nextNode : adj[curNode]){
        if(nextNode == prevNode) continue;
        dfs(nextNode, curNode);
        longestPathToLeaf[curNode] = max(longestPathToLeaf[curNode], longestPathToLeaf[nextNode]);

        if(longestPathToLeaf[nextNode] > firstLongest){
            secondLongest = firstLongest;
            firstLongest = longestPathToLeaf[nextNode];
        }
        else if(longestPathToLeaf[nextNode] > secondLongest){
            secondLongest = longestPathToLeaf[nextNode];
        }
    }

    if(adj[curNode].size() > 1) longestPathToLeaf[curNode]++;
    maxPathToLeaf[curNode] = firstLongest + secondLongest + min((int) adj[curNode].size(), 2);
}

int main() {

    //freopen("tree.in" , "r" , stdin);

    long long n; cin >> n;
    for(long long i=1; i<n; i++){
        long long a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1,0);

    long long ans = 0;
    for(int i=1; i<=n; i++){
        ans = max(ans, maxPathToLeaf[i]);
    }

    cout << ans << endl;
    return 0;

}