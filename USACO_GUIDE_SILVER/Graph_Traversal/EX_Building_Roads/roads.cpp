#include <bits/stdc++.h>
using namespace std;

int n, m, ans;
vector<int> rep;
map<int, vector<int>> adj;
vector<bool> visited;

void dfs(int node)
{
    visited[node] = true;
    for (int x : adj[node])
    {
        if (!visited[x])
            dfs(x);
    }
}

int build_roads()
{
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            rep.push_back(i);
            dfs(i);
        }
    }
    return rep.size() - 1;
}

int main()
{
    //freopen("roads.in", "r", stdin);

    cin >> n >> m;
    visited.resize(n+1); //one-index the cities

    int cityOne, cityTwo;
    for (int i = 0; i < m; i++)
    {
        cin >> cityOne >> cityTwo;
        adj[cityOne].push_back(cityTwo);
        adj[cityTwo].push_back(cityOne);
    }

    ans = build_roads();
    cout << ans << endl;

    for (int i = 0; i < ans; i++)
    {
        cout << rep[i] << " " << rep[i + 1] << endl;
    }
}