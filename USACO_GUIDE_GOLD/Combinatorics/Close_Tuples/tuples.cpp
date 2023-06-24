#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;
const ll MAXN = 2 * 1e5;

ll fac[MAXN + 1];
ll inv[MAXN + 1];

ll modpow(ll a, ll x){
    if(x == 0) return 1;
    if(x % 2 == 0){
        ll k = modpow(a, x/2);
        return (k*k) % MOD;
    }
    else{
        ll k = modpow(a, x-1);
        return (a*k) % MOD;
    }
}

void fillFac(){
    fac[0] = 1;
    for(ll i=1; i<=MAXN; i++){
        fac[i] = (i * fac[i-1]) % MOD;
    }
}

void fillInv(){
    inv[MAXN] = modpow(fac[MAXN] , MOD-2);
    for(ll i=MAXN-1; i>=0; i--){
        inv[i] = (i+1)*(inv[i+1]) % MOD;
    }
}

//return a choose b
ll choose(ll a, ll b){
    ll temp = (fac[a])*(inv[b]) % MOD;
    return (temp)*(inv[a-b]) % MOD;
}

void solve(){
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> nums(n);
    for(ll i=0; i<n; i++){
        cin >> nums[i];
    }
    sort(nums.begin() , nums.end(), greater<ll>());

    //two ptrs
    ll ans = 0, l = 0, r = m-1;
    while(r < n){
        while(r < n-1 && nums[l] - nums[r+1] <= k) r++;
        if(r-l+1>=m && nums[l] - nums[r] <= k) ans = (ans + choose(r-l , m-1)) % MOD;
        else if(r==n-1) break;
        l++;
    }

    cout << ans << endl;
    return;
}

int main(){

    fillFac();
    fillInv();

    //freopen("tuples.in" , "r" , stdin);

    //sort numbers in decreasing order
    //keep hi and lo boundaries with 2 ptrs
    //take combo of each and sum all to get ans

    int t; cin >> t;
    for(int i=0; i<t; i++){
        solve();
    }

}