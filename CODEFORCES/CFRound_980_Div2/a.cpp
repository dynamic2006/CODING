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
        int a, b; cin >> a >> b;
        if(b <= a){
            cout << a << endl;
        }
        else if(b-a <= a){
            cout << 2*a-b << endl;
        }
        else{
            cout << 0 << endl;
        }
    }
}