#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll MAXN = 2*1e5;
const ll MOD = 1e9 + 7;

ll fac[MAXN+1];
ll inv[MAXN+1];

ll modpow(ll x, ll n)
{
    if(n == 0) return 1;
    ll u = modpow(x, n/2);
    u = (u*u) % MOD;
    if(n%2 == 1) u = (u*x) % MOD;
    return u;
}

void factorial()
{
    fac[0] = 1;
    for(int i=1; i<=MAXN; i++) fac[i] = (i)*(fac[i-1])%MOD;
}

void inverses()
{
    inv[MAXN] = modpow(fac[MAXN], MOD-2);
    for(int i=MAXN; i>=1; i--){
        inv[i-1] = (i)*(inv[i]) % MOD;
    }
}

ll choose(ll n, ll r)
{
    return(((fac[n] * inv[r]) % MOD) * ((inv[n-r]) % MOD)) % MOD;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    factorial();
    inverses();

    // cout << "CHECK" << endl;

    // freopen("f.in", "r", stdin);

    int t; cin >> t;
    while(t--){
        ll n, k; cin >> n >> k;
        ll a = (k+1)/2;
        ll oneCount = 0;

        // cout << "CHECK" << endl;

        vector<int> nums(n);
        for(int i=0; i<n; i++){
            cin >> nums[i];
            if(nums[i] == 1) oneCount++;
        }
        ll zeroCount = n-oneCount;

        // cout << "CHECK" << endl;

        ll ans = 0;
        // ll counter = 0;
        for(ll i=max(a, k-zeroCount); i<=k; i++){
            if(i > oneCount || (k-i) > zeroCount) break;
            ans += (choose(oneCount,i)%MOD)*(choose(zeroCount, k-i)%MOD)%MOD;
            ans %= MOD;
            // cout << ans << endl;
            // counter++;
            // if(counter > 70) break;
        }
        cout << ans << endl;

    }
}