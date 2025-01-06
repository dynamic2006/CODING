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
        ll r, c; cin >> r >> c;

        ll ans = 1;
        if(r >= c){
            ans += r/2 + (r-1)/2;
            ans += (r-2)*(r-1);
            if(r%2){
                ans += c-1;
            }
            else{
                ans += r-1;
                ans += r-c;
            }
        }
        else{
            ans += c/2 + (c-1)/2;
            ans += (c-2)*(c-1);
            if(c%2){
                ans += c-1;
                ans += c-r;
            }
            else{
                ans += r-1;
            }
        }
        cout << ans << endl;
    }

}