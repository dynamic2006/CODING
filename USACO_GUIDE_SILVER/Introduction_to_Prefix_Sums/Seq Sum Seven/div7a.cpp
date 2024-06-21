#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    freopen("div7.in" , "r" , stdin);
    freopen("div7.out" , "w" , stdout);

    ll n; cin >> n;
    vector<ll> ids(n);
    for(ll i=0; i<n; i++) cin >> ids[i];

    ll arr[7];
    fill(arr, arr+7, -1);

    vector<ll> prefix(n);
    prefix[0] = ids[0];
    arr[ids[0] % 7] = 0;
    ll ans = 0;

    for(ll i=1; i<n; i++){
        prefix[i] = prefix[i-1] + ids[i];
        ll modulo = prefix[i] % 7;
        if(arr[modulo] == -1) arr[modulo] = i;
        if(arr[modulo] >= 0) ans = max(ans, i - arr[modulo]);
        //cout << "PREFIX " << prefix[i] << " COMPARE " << arr[modulo] << endl;
    }

    cout << ans << endl;

}