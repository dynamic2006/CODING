#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MAXNUM = 1e18;

struct Interval
{
    ll start, end;
};

bool cmp(const Interval& a, const Interval& b){
    return a.start < b.start;
}

ll n, m;
vector<Interval> intervals;

bool valid(ll d){
    ll placedCows = 0;
    ll lastPlacement = -1;

    for(auto interval : intervals){
        //cout << d << " " << lastPlacement << " " << placedCows << endl;
        lastPlacement = max(interval.start, lastPlacement);
        //cout << d << " " << lastPlacement << " " << placedCows << endl;
        if(lastPlacement > interval.end) continue;
        ll addCows = (interval.end - lastPlacement)/d + 1;
        placedCows += addCows;
        lastPlacement += d*addCows;
        if(placedCows >= n) return true;
    }

    return false;

}

ll binarySearch(ll lo, ll hi)
{
    lo--;
    while(lo<hi){
        ll mid = lo + (hi-lo+1)/2;
        if(valid(mid)) lo = mid;
        else hi = mid-1;
        //cout << endl;
    }
    return lo;
}

int main()
{
    freopen("socdist.in" , "r" , stdin);
    freopen("socdist.out" , "w" , stdout);

    cin >> n >> m;

    intervals.resize(m);

    for(ll i=0; i<m; i++){
        cin >> intervals[i].start >> intervals[i].end;
    }
    sort(intervals.begin(), intervals.end(), cmp);

    ll ans = binarySearch(1, MAXNUM);
    cout << ans << endl;


}
//IDEAS
//binary search on max val D
//to check use greedy:
//place cows exactly D away,
//starting from min position possible
//check if all cows can fit in intervals