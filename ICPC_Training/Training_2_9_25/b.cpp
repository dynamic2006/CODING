#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.in", "r", stdin);

    int n, m; cin >> n >> m;
    vector<bool> cols(n,false);

    int maxAns = m;
    for(int i=0; i<n; i++){
        char x; cin >> x;
        if(x == '1') cols[i] = true;
    }

    int counter = 0;
    int ans = 0;
    for(int i=0; i<n; i++){

        if(counter == 2){
            if(i<=n-3){
                if(cols[i+1]) cols[i+2] = cols[i+1];
                cols[i+1] = false;
            }
            if(i>=2){
                if(cols[i-1]) cols[i-2] = cols[i-1];
                cols[i-1] = false;
            }
            cols[i] = false;
            counter = 0;
            ans++;
        }
        else if(cols[i]){
            counter++;
        }
        else counter = 0;
    }
    for(int i=0; i<n; i++){
        if(cols[i]) ans++;
    }
    cout << min(ans, maxAns) << endl;
    
}