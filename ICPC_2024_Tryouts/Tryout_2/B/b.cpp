#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.in", "r", stdin);

    int k; cin >> k;
    int barSize = 1;
    int minCuts = 0;
    while(barSize < k){
        barSize*=2;
        minCuts++;
    }

    if(k == barSize){
        cout << barSize << " 0" << endl;
        return 0;
    }

    for(int i=0; i<21; i++){
        if(k & (1 << i)){
            cout << barSize << " " << minCuts << endl;
            return 0;
        }
        minCuts--;
    }
}