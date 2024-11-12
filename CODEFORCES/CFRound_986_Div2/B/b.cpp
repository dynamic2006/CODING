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
        ll n, b, c; cin >> n >> b >> c;
        if(b == 0 && c == 0 && n == 1){
            cout << 0 << endl;
            continue;
        }
        else if(b == 0){
            if(n-c > 2){
                cout << -1 << endl;
                continue;
            }
            else if(n-c == 1 || n-c == 2){
                cout << n-1 << endl;
                continue;
            }
            else{
                cout << n << endl;
                continue;
            }
        }


        ll covered = max((ll)ceil((n-c)/((double)b)), (ll)0);
        // cout << "COVERED " << covered << " ";
        cout << n - covered << endl;
    }
}