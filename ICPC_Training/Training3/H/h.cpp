#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.in", "r", stdin);

    int n, m, q; cin >> n >> m >> q;
    vector<string> grid(n+1);
    for(int i=1; i<=n; i++) cin >> grid[i];

    vector<bool> validppl(n+1, true);
    validppl[0] = false;
    for(int i=0; i<q; i++){
        int at; cin >> at;
        char ans; cin >> ans;
        for(int j=1; j<=n; j++){
            if(grid[j][at-1] != ans) validppl[j] = false;
        }
    }

    int found = -1;
    int count = 0;
    for(int i=1; i<=n; i++){
        if(validppl[i]){
            found = i;
            count++;
        }
    }

    if(count > 1){
        cout << "ambiguous" << endl;
        cout << count << endl;
    }
    else{
        cout << "unique" << endl;
        cout << found << endl;
    }

}