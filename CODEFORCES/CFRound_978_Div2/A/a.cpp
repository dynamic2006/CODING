#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.in", "r", stdin);

    int t; cin >> t;
    while(t--){
        int n, r; cin >> n >> r;
        int usedRows = 0, leftOver = 0, total = 0;
        for(int i=0; i<n; i++){
            int a; cin >> a;
            total += a;
            usedRows += a/2;
            leftOver += (a%2);
        }
        int extraRows = r - usedRows;
        leftOver = max(0, (leftOver - extraRows));
        cout << total - 2*leftOver << endl;
    }
}