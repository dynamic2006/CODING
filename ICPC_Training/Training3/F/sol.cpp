#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int TIMES = 86400;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.in", "r", stdin);

    int n; cin >> n;
    vector<int> diffTable(TIMES+1, 0);
    for(int i=0; i<n; i++){
        int m; cin >> m;
        for(int j=0; j<m; j++){
            int a, b; cin >> a >> b;
            diffTable[a]++; diffTable[b+1]--;
        }
    }

    int maxAns = 0;
    for(int i=1; i<=TIMES; i++){
        diffTable[i] += diffTable[i-1];
        maxAns = max(maxAns, diffTable[i]);
    }

    int count = 0;
    for(int i=0; i<=TIMES; i++){
        if(diffTable[i] == maxAns) count++;
    }

    cout << maxAns << endl;
    cout << count << endl;
}