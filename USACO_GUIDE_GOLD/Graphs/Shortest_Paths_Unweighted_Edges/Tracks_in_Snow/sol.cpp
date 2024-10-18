#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int h, w;
vector<string> grid;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("input.in", "r", stdin);

    cin >> h >> w;
    grid = vector<string>(h);
    for(int i=0; i<h; i++){
        cin >> grid[i];
    }

    //bfs tree with connected components
    //ans is depth of the tree
    //can treat as edges with 0 weight to same component
    //1 weight to edge to diff component
    
}