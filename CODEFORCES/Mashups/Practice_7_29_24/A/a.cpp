#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("a.in", "r", stdin);

    int t; cin >> t;
    while(t--){
        string a, b; cin >> a >> b;
        char temp = b[0];
        b[0] = a[0];
        a[0] = temp; 
        cout << a << " " << b << endl;
    }
}