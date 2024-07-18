#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("b.in" , "r" , stdin);

    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        int left = max(0, n-m);
        int right = n+m;
        
        int ans = 0;
        for(int i=0; i<32; i++){
            if(left & (1<<i) || right & (1<<i)) ans |= (1<<i);
            else if(i<31 && left>>(i+1) != right>>(i+1)) ans |= (1<<i);
            else ans &= ~(1<<i);

            //cout << ans << " ";
        }
        //cout << endl;
        cout << ans << endl;
    }
}