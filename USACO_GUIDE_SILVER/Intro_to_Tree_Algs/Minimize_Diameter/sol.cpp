#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void dfs(int cur, int prev, vector<vector<int>>& adj, vector<int>& firstMax, vector<int>& secondMax, vector<int>& c)
{
    firstMax[cur] = 0; secondMax[cur] = 0;
    for(auto &next : adj[cur]){
        if(next == prev) continue;
        dfs(next, cur, adj, firstMax, secondMax, c);
        if(firstMax[next] + 1 > firstMax[cur]){
            secondMax[cur] = firstMax[cur];
            firstMax[cur] = firstMax[next] + 1;
            c[cur] = next;
        }
        else if(firstMax[next]+1 > secondMax[cur]){
            secondMax[cur] = firstMax[next] + 1;
        }
    }
}

void dfs2(int cur, int prev, vector<vector<int>>& adj, vector<int>& firstMax, vector<int>& secondMax, vector<int>& c)
{
    for(auto &next : adj[cur]){
        if(next == prev) continue;
        if(c[cur] == next){
            if(firstMax[next] < secondMax[cur]+1){
                secondMax[next] = firstMax[next];
                firstMax[next] = secondMax[cur] + 1;
                c[next] = cur;
            }
            else secondMax[next] = max(secondMax[cur]+1, secondMax[next]);
        }
        else{
            secondMax[next] = firstMax[next];
            firstMax[next] = firstMax[cur]+1;
            c[next] = cur;
        }
        dfs2(next, cur, adj, firstMax, secondMax, c);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.in", "r", stdin);

    int n; cin >> n;
    vector<vector<int>> adj1(n+1, vector<int>());
    vector<int> firstMax1(n+1), secondMax1(n+1), c1(n+1);
    for(int i=0; i<n-1; i++){
        int a, b; cin >> a >> b;
        adj1[a].push_back(b);
        adj1[b].push_back(a);
    }

    int m; cin >> m;
    vector<vector<int>> adj2(m+1, vector<int>());
    vector<int> firstMax2(m+1), secondMax2(m+1), c2(m+1);
    for(int i=0; i<m-1; i++){
        int a, b; cin >> a >> b;
        adj2[a].push_back(b);
        adj2[b].push_back(a);
    }

    dfs(1, 0, adj1, firstMax1, secondMax1, c1);
    dfs2(1, 0, adj1, firstMax1, secondMax1, c1);

    dfs(1, 0, adj2, firstMax2, secondMax2, c2);
    dfs2(1, 0, adj2, firstMax2, secondMax2, c2);

    sort(firstMax1.begin(), firstMax1.end());
    sort(firstMax2.begin(), firstMax2.end());


    cout << max(firstMax1[1] + firstMax2[1] + 1, max(firstMax1[n], firstMax2[m])) << endl;

}