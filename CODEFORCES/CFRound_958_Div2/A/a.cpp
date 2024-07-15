#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("a.in" , "r" , stdin);

    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        int ans = 0;
        if(n == 1){
            cout << 0 << endl;
            continue;
        }
        if(n >= k){
            n -= k; ans++;
        }
        ans += (n+k-2)/(k-1);

        cout << ans << endl;
    }
}