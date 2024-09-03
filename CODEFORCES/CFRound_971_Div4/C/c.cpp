#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("c.in", "r", stdin);

    int t; cin >> t;
    while(t--){
        ll x, y, k; cin >> x >> y >> k;
        ll xMoves = (x+k-1)/k;
        ll yMoves = (y+k-1)/k;
        if(yMoves < xMoves){
            yMoves = xMoves - 1;
        }
        if(xMoves < yMoves){
            xMoves = yMoves;
        }
        cout << xMoves + yMoves << endl;
    }
}