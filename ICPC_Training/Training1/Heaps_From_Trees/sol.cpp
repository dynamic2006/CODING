#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
vector<int> nodes;
vector<vector<int>> adj;
vector<pair<int, int>> dp;

multiset<int>* dfs(int cur)
{
    multiset<int>* values = new multiset<int>();

    //small to large merging
    for(auto &next : adj[cur]){
        multiset<int>* childValues = dfs(next);
        if(values->size() < childValues->size()){
            swap(values, childValues);
        }
        values->insert(childValues->begin(), childValues->end());
        dp[cur].first += max(dp[next].first, dp[next].second);
        auto k = values->lower_bound(nodes[cur]);

        delete childValues;
    }

    //set for cur node is now finished

    //calculate dp for cur node
    return values;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("input.in", "r", stdin);

    cin >> n;
    nodes = vector<int>(n+1);
    adj = vector<vector<int>>(n+1, vector<int>());
    dp = vector<pair<int, int>>(n+1, {-1,-1});

    for(int i=1; i<=n; i++){
        int v, p; cin >> v >> p;
        nodes[i] = v;
        adj[p].push_back(i);
    }

    //dfs thru tree
    //small to large merging
    //for each node, keep set of all numbers below that are smaller
    //set allow for nlogn time complexity
    //for each node, go thru children on backtracking
    //and small-to-large merge children sets to form node set

    //also need to keep dp for max answer
    //dp transition
    //dp[i][0] = max ans if we don't take node i in subset
    //= sum over all children j of i: max(dp[j][0], dp[j][1])
    //dp[i][1] = max ans if we DO take node i in subset
    //= sum over all VALID children j of i: largest valid j subset size
    //at end, iterate thru all dp[i][j] and get max ans

}