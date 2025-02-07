#include <bits/stdc++.h>
using namespace std;

#include <bits/extc++.h>
using namespace __gnu_pbds;
template<class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.in", "r", stdin);

    ll n, m, q; cin >> n >> m >> q;

    vector<pair<ll, ll>> a(m, {0,0});
    for(ll i=0; i<m; i++) a[i].second = i+1;
    for(ll i=0; i<n; i++){
        ll x; cin >> x;
        a[x-1].first++;
    }

    //sort cities by occs first, then secondarily by og idx
    sort(a.begin(), a.end());
    //stores the first year that sorted city i is included in cycle
    vector<ll> firstYears(m);
    ll counter = n+1;
    for(ll i=0; i<m-1; i++){
        firstYears[i] = counter;
        counter += (i+1) * (a[i+1].first - a[i].first);
    }
    firstYears[m-1] = counter;

    Tree<ll> t;

    vector<ll> years(q);
    for(ll i=0; i<q; i++) cin >> years[i];
    vector<ll> sortedYears = years;
    sort(sortedYears.begin(), sortedYears.end());
    sortedYears.erase(unique(sortedYears.begin(), sortedYears.end()), sortedYears.end());

    map<ll, ll> ans;
    ll firstOutCity = 0;
    for(ll i=0; i<sortedYears.size(); i++){
        ll yr = sortedYears[i];
        //answer the city for yr
        ll interestSize = 0;
        ll k = 0;
        if(yr >= firstYears[m-1]){
            //in this case, the cycle is all of the m cities
            interestSize = m;
            k = firstYears[m-1];
        }
        else{
            auto it = prev(upper_bound(firstYears.begin(), firstYears.end(), yr));
            interestSize = it - firstYears.begin() + 1;
            k = *it;
        }

        for(ll i=firstOutCity; i<interestSize; i++){
            t.insert(a[i].second);
        }
        firstOutCity = interestSize;
        ll j = ((yr - k)%interestSize);
        ans[yr] = *t.find_by_order(j);
    }

    for(ll i=0; i<q; i++){
        cout << ans[years[i]] << endl;
    }
}