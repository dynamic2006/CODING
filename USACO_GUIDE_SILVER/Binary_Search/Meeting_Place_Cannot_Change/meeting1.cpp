#include <bits/stdc++.h>
using namespace std;

const double MAXNUM = 1e9;
const double EPSILON = 1e-7;

int n;
vector<int> coords;
vector<int> speeds;

bool valid(double time)
{
    double lowerBound = -1;
    double upperBound = MAXNUM+1;
    for(int i=0; i<n; i++){
        lowerBound = max(lowerBound, coords[i] - time*speeds[i]);
        upperBound = min(upperBound, coords[i] + time*speeds[i]);
    }
    if(upperBound >= lowerBound) return true;
    return false;
}

double binarySearch(double lo, double hi)
{
    hi++;
    while(hi-lo > EPSILON){
        double mid = lo + (hi-lo)/2;
        if(valid(mid)) hi = mid;
        else lo = mid+EPSILON;
    }
    return lo;
}

int main()
{
    //freopen("meeting.in" , "r" , stdin);

    cin >> n;
    coords.resize(n);
    speeds.resize(n);

    for(int i=0; i<n; i++){
        cin >> coords[i];
    }
    for(int i=0; i<n; i++){
        cin >> speeds[i];
    }

    double ans = binarySearch(0, MAXNUM);
    cout << fixed << ans << endl;
}
//IDEAS
//binary search on min time to meet t
//variation: need hi and lo to be within 10^-7 of each other to quit search
//for given t, iterate over all friends
//find interval that each friend can reach within t seconds
//keep bounds overall on interval that all friends so far can meet in
//if, at end, interval is NOT empty, then t is valid time