#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll MAXNUM = 1e13;

map<char, ll> ingreds;
ll nb, ns, nc;
ll pb, ps, pc;
ll r;

bool valid(ll burgers)
{
    ll cost = 0;
    cost += max((ll)0, (burgers*ingreds['B'] - nb)*pb);
    cost += max((ll)0, (burgers*ingreds['S'] - ns)*ps);
    cost += max((ll)0, (burgers*ingreds['C'] - nc)*pc);
    if(cost <= r) return true;
    return false;
}

ll binarySearch(ll lo, ll hi)
{
    lo--;
    while(lo<hi){
        ll mid = lo + (hi-lo+1)/2;
        if(valid(mid)) lo = mid;
        else hi = mid-1;
    }
    return lo;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.in", "r", stdin);

    string s; cin >> s;
    for(int i=0; i<s.size(); i++){
        ingreds[s[i]]++;
    }
    cin >> nb >> ns >> nc;
    cin >> pb >> ps >> pc;
    cin >> r;

    ll ans = binarySearch(0, MAXNUM);
    cout << ans << endl;

}