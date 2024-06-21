#include <bits/stdc++.h>
using namespace std;

const double MAXNUM = 1e9;

int n;
vector<int> locations;

bool validMaxPos(double maxPos, double r)
{
    double pos = maxPos, prevPos = MAXNUM+1;
    while(pos>locations[0]){
        if(r <= 0) return false;
        if(pos == prevPos) return false;

        prevPos = pos;
        auto it = lower_bound(locations.begin() , locations.end() , pos-r);
        if(it == locations.end()) return false;
        pos = *it;

        r--;
    }
    return true;
}

double binarySearchMaxPos(double lo, double hi, double r)
{
    lo--;
    while(lo+0.01<hi){
        double mid = lo + (hi-lo)/2;
        if(validMaxPos(mid, r)) lo=mid;
        else hi = mid-0.01;
    }
    return lo;
}

bool valid(double r)
{
    double maxPos = binarySearchMaxPos(locations[0], locations[n-1], r);
    double pos = maxPos, prevPos = -1;
    while(pos<locations[n-1]){
        if(r <= 0) return false;
        if(pos == prevPos) return false;
        prevPos = pos;
        pos = *prev(upper_bound(locations.begin(), locations.end(), prevPos+r));
        r--;
    }
    return true;
}

double binarySearch(double lo, double hi)
{
    hi++;
    while(lo + 0.01 < hi){
        double mid = lo + (hi-lo)/2;
        //cout << "CHECKING " << mid << endl;
        if(valid(mid)) hi = mid;
        else lo = mid+0.01;
    }
    return lo;
}

int main()
{
    freopen("angry.in" , "r" , stdin);
    freopen("angry.out" , "w" , stdout);

    cin >> n;
    locations.resize(n);
    for(double i=0; i<n; i++) cin >> locations[i];
    sort(locations.begin() , locations.end());

    double ans = binarySearch(1, MAXNUM);
    cout << fixed << setprecision(1) << ans << endl;
}
//IDEAS
//binary search on min value of power R
//for given R, binary search on max pos cow can be launched at
//and still detonate all haybales to left of it
//then, in og binary search, check if all haybales to right are exploded
//if all haybales explode, then valid, else not valid