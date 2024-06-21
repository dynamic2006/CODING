#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    //freopen("aa.in" , "r" , stdin);

    map<ll, ll> nums;
    
    ll q; cin >> q;
    for(int i=0; i<q; i++){
        int a; cin >> a;
        if(a == 0){
            ll k, v; cin >> k >> v;
            nums[k] = v;
        }
        else{
            ll k; cin >> k;
            cout << nums[k] << endl;
        }
    }
}