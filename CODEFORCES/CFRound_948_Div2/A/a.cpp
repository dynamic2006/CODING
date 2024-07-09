#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("a.in" , "r" , stdin);

    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        if(n >= m && n%2 == m%2) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}