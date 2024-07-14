#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("b.in" , "r" , stdin);

    int t; cin >> t;
    while(t--){
        ll n, a, b; cin >> n >> a >> b;
        if(a >= b) cout << n*a << endl;
        else{
            ll ans = 0;
            if(n >= b-a){
                ans = (b-a)*(b+a+1)/2;
                ans += a*(n-(b-a));
            }
            else{
                ans = (n)*(2*b-n+1)/2;
            }
            cout << ans << endl;
        }
    }
}