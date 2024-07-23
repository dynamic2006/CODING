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
        int n, k; cin >> n >> k;
        int ans = 0;
        if(k>=n){
            ans++;
            k-=n;
        }
        for(int i=n-1; i>=1; i--){
            for(int j=1; j<=2; j++){
                if(k>=i){
                    ans++;
                    k-=i;
                }
                else break;
            }
        }
        if(k>0) ans++;
        cout << ans << endl;
    }
}