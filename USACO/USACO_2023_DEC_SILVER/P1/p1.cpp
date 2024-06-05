#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MAXNUM = 1e15;

map<ll, ll> towers;

int main(){

    freopen("p1.in" , "r" , stdin);

    vector<pair<ll, ll>> blocks;
    
    int n, m, k; cin >> n >> m >> k;
    for(int i=0; i<n; i++){
        ll a, w; cin >> w >> a;
        blocks.push_back({-w,a});
    }

    sort(blocks.begin() , blocks.end());

    ll ans = 0;
    towers[MAXNUM] = m;
    for(auto x : blocks){
        ll weight = -x.first, amt = x.second;
        auto a = lower_bound(towers.begin(), towers.end(), weight + k);
        while (a != towers.end()){
            ll addedBlocks = min(a->second, amt);
            a->second -= addedBlocks;
            amt -= addedBlocks;
            ans += addedBlocks;
            towers[weight] += addedBlocks;
        }
    }

    cout << ans << endl;

}

//IDEAS
//make vector of pairs of {a_i, w_i}
//pretend you have M towers, each currently empty
//sort vector of pairs
//iterate through all pairs in vector
//IF the weight w_i
//ans += min(a_i, M)