#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("b.in" , "r" , stdin);

    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        vector<ll> pieces(k);
        for(int i=0; i<k; i++) cin >> pieces[i];
        sort(pieces.begin() , pieces.end() , greater<int>());
        
        ll ans = 0;
        for(int i=1; i<k; i++){
            ans += 2*pieces[i] - 1;
        }
        cout << ans << endl;
    }
}