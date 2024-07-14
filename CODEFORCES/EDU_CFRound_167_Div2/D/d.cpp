#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MAXNUM = 1e6;

struct Weapon
{
    ll cost, ingotLoss;
};
bool cmp(Weapon& a, Weapon& b){
    if(a.ingotLoss == b.ingotLoss) return a.cost < b.cost;
    return a.ingotLoss < b.ingotLoss;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("d.in" , "r" , stdin);

    ll n, m; cin >> n >> m;
    vector<Weapon> weaponsog(n); //first is return, second is initial cost
    vector<ll> metals(m);

    for(ll i=0; i<n; i++) cin >> weaponsog[i].cost;
    for(ll i=0; i<n; i++){
        ll ingots; cin >> ingots;
        weaponsog[i].ingotLoss = weaponsog[i].cost - ingots;
    }
    for(ll i=0; i<m; i++) cin >> metals[i];

    sort(weaponsog.begin() , weaponsog.end() , cmp);

    // ll safe = 0;
    //plz plz don't inf loop me
    vector<Weapon> weapons;
    weapons.push_back(weaponsog[0]);
    for(ll i=1; i<n; i++){
        if(weaponsog[i].cost < weapons.back().cost) weapons.push_back(weaponsog[i]);
    }

    vector<ll> costs;
    for(auto x : weapons) costs.push_back(-x.cost);

    vector<ll> dp(MAXNUM+1,0);
    for(ll i=1; i<=MAXNUM; i++){
        auto it = lower_bound(costs.begin(), costs.end(), -i);
        if(it != costs.end()){
            ll idx = it - costs.begin();
            dp[i] = 1 + dp[i - weapons[idx].ingotLoss];
        }
        else dp[i] = 0;
    }

    ll totalexp = 0;
    for(ll i=0; i<m; i++){
        if(metals[i] > MAXNUM){
            metals[i] -= weapons[0].cost;
            ll div = weapons[0].cost - weapons[0].ingotLoss;
            totalexp += 2*(metals[i]/weapons[0].ingotLoss + 1);
            metals[i] %= weapons[0].ingotLoss;
            metals[i] += weapons[0].cost - weapons[0].ingotLoss;
        }
        totalexp += 2*dp[metals[i]];
    }

    cout << totalexp << endl;
}