#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
vector<vector<int>> adj;
vector<int> firstMax, secondMax, c;

void dfs(int cur, int prev)
{
    firstMax[cur] = 0; secondMax[cur] = 0;
    for(auto &next : adj[cur]){
        if(next == prev) continue;
        dfs(next, cur);
        if(firstMax[next] + 1 > firstMax[cur]){
            secondMax[cur] = firstMax[cur];
            firstMax[cur] = firstMax[next] + 1;
            c[cur] = next;
        }
        else if(firstMax[next] + 1 > secondMax[cur]){
            secondMax[cur] = firstMax[next] + 1;
        }
    }
}

void dfs2(int cur, int prev)
{
    for(auto &next : adj[cur]){
        if(next == prev) continue;
        if(c[cur] == next){
            if(firstMax[next] < secondMax[cur] + 1){
                secondMax[next] = firstMax[next];
                firstMax[next] = secondMax[cur] + 1;
                c[next] = cur;
            }
            else secondMax[next] = max(secondMax[cur]+1, secondMax[next]);
        }
        else{
            secondMax[next] = firstMax[next];
            firstMax[next] = firstMax[cur] + 1;
            c[next] = cur;
        }
        dfs2(next, cur);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.in", "r", stdin);

    cin >> n;
    adj = vector<vector<int>>(n+1, vector<int>());
    firstMax = vector<int>(n+1);
    secondMax = vector<int>(n+1);
    c = vector<int>(n+1);

    for(int i=0; i<n-1; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 0);
    dfs2(1, 0);

    for(int i=1; i<=n; i++){
        cout << firstMax[i] << " ";
    }
    cout << endl;

}