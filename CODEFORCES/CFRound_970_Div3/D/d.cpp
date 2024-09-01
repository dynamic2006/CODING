#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> perm;
vector<bool> vis;
vector<int> ans;
vector<int> idxes;
string s;

void dfs(int cur, int blackNodeCount, int compSize){
    if(vis[cur]){
        for(auto &i : idxes){
            ans[i-1] = blackNodeCount;
        }
        return;
    }

    vis[cur] = true; idxes.push_back(cur);
    if(s[cur-1] == '0') blackNodeCount++;
    compSize++;

    dfs(perm[cur], blackNodeCount, compSize);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("d.in", "r", stdin);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        perm = vector<int>(n+1);
        vis = vector<bool>(n+1, false);
        ans = vector<int>(n);

        for(int i=1; i<=n; i++){
            cin >> perm[i];
        }
        cin >> s;
    
        for(int i=1; i<=n; i++){
            if(!vis[i]){
                idxes.clear();
                dfs(i, 0, 0);
            }
        }

        for(auto &x : ans){
            cout << x << " ";
        }
        cout << endl;

    }
}