#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.in", "r", stdin);

    ll n; cin >> n;

    cout << n << " ";
    
    while(n>1){
        if(n%2) n = 3*n + 1;
        else n /= 2;
        cout << n << " ";
    }
    cout << endl;
}