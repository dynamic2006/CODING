#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MAXN = 1e6;
const ll MAXMOD = 1e9;

int main(){

    //freopen("montmort.in" , "r" , stdin);

    ll n, m; cin >> n >> m;
    ll curAns = 0; //derangements for 1
    ll sign = 1; //tracks +/- 1 at the end

    //each next number can be calculated
    //by using the previous answer x
    //and multiplying it by the current number i
    //then just adding or subtracting 1 as needed
    cout << curAns << " ";
    for(ll i=2; i<=n; i++){
        curAns = (curAns * i + (sign)*(1)) % m;
        sign = -sign;
        cout << curAns << " ";
    }
    cout << endl;
    return 0;

}