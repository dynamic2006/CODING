#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>
#include <set>
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
#define INF 2e9
//dp[done][seen]
int main() {

    freopen("input.in" , "r" , stdin);
    
    int n, m; cin >> n >> m;
    int deg[n+1];
    set<int> edges[n+1];
    for(int i = 0; i <= n; i++) {
        deg[i] = 0;
    }
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        deg[a]++;
        deg[b]++;
        edges[a].insert(b);
        edges[b].insert(a);
    }
    int ans = 0;
    for(int i = 1; i<=n; i++) {
        //cout << deg[i] << endl;
        if(deg[i] % 2 == 1) {
            ans++;
        }
    }
    cout << ans << endl;
    for(int i = 1; i <= n; i++) {
        int cur = i;
        while(deg[cur] > 0) {
            set<int>::iterator it = edges[cur].begin();
            int next = *it;
            edges[cur].erase(it);
            edges[next].erase(cur);
            deg[cur]--;
            deg[next]--;
            cout << cur << " " << next << endl;
            cur = next;
        }
    }
    return 0;
    //cout << val << endl;
}