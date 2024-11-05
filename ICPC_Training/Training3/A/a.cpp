#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int m, n;
vector<vector<pair<int, int>>> adj;
map<string, int> classesIdx;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("input.in", "r", stdin);

    cin >> m >> n;
    adj = vector<vector<pair<int ,int>>>(m+n+1, vector<pair<int, int>>());
    int curIdx = 1;
    for(int i=0; i<m; i++){
        string name; cin >> name;
        if(!classesIdx.count(name)){
            classesIdx[name] = curIdx;
            adj[curIdx].push_back()
        }
        else{
            
        }
    }

}