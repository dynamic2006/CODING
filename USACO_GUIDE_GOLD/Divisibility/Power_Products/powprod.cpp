#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MAXN = 1e5;
const ll MAXK = 100;

map<vector<pair<ll, ll>> , ll> occs;
vector<vector<pair<ll, ll>>> factorizations;

vector<pair<ll, ll>> getFactorization(ll a, ll k){
    ll temp = a;
    vector<pair<ll,ll>> factorization;
    for(ll i=2; i*i <=temp; i++){
        ll exp = 0;
        while(a % i == 0){
            exp++;
            a /= i;
        }
        if(exp % k != 0){
            factorization.push_back({i, exp % k});
        }
    }
    if(a > 1) factorization.push_back({a, 1});
    return factorization;
}

vector<pair<ll,ll>> getComplement(vector<pair<ll,ll>> fac, ll k){
    vector<pair<ll,ll>> complement;
    for(auto p : fac){
        complement.push_back({p.first, k - p.second});
    }
    return complement;
}

int main(){

    //freopen("powprod.in" , "r" , stdin);

    ll n, k; cin >> n >> k;
    vector<ll> nums;
    for(ll i=0; i<n; i++){
        ll a; cin >> a;
        nums.push_back(a);
        vector<pair<ll,ll>> curFactorization = getFactorization(a , k);
        factorizations.push_back(curFactorization);
        occs[curFactorization]++;
    }

    ll ans = 0;
    for(auto f : factorizations){
        vector<pair<ll,ll>> complement = getComplement(f,k);
        ans += occs[complement];
        if(complement == f) ans--;
    }

    cout << ans/2 << endl;
    return 0;


}

//ideas
//make a map that maps a prime factorization to #of occurences
//make sure to not overcount if a number's complement is itself