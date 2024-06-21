#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, x_1, x_2, y_1, y_2;
ll xChangeCycle, yChangeCycle; //hehe xChange
string s;

map<char, pair<ll, ll>> directions;

bool valid(ll days)
{
    ll fullCycles = days/n;
    ll leftoverDays = days - fullCycles*n;
    ll xtemp = x_1, ytemp = y_1;

    xtemp += fullCycles*xChangeCycle;
    ytemp += fullCycles*yChangeCycle;
    for(ll i=0; i<leftoverDays; i++){
        xtemp += directions[s[i]].first;
        ytemp += directions[s[i]].second;
    }

    ll totalDiff = abs(x_2 - xtemp) + abs(y_2 - ytemp);
    if(totalDiff <= days) return true;
    return false;
}

ll binarySearch(ll lo, ll hi)
{
    hi++;
    while(lo<hi){
        ll mid = lo + (hi-lo)/2;
        //cout << "TRYING " << mid << " DAYS" << endl;
        if(valid(mid)) hi = mid;
        else lo = mid+1;
    }
    return lo;
}

int main()
{
    directions['U'] = {0,1};
    directions['D'] = {0,-1};
    directions['R'] = {1,0};
    directions['L'] = {-1,0};

    //freopen("magic.in" , "r" , stdin);

    cin >> x_1 >> y_1;
    cin >> x_2 >> y_2;
    cin >> n;
    cin >> s;

    xChangeCycle = 0;
    yChangeCycle = 0;
    for(ll i=0; i<n; i++){
        xChangeCycle += directions[s[i]].first;
        yChangeCycle += directions[s[i]].second;
    }
    ll totalDiff = abs(x_2-x_1) + abs(y_2-y_1);

    ll ans = binarySearch(1, n*totalDiff);
    if(ans > n*totalDiff) cout << "-1" << endl;
    else cout << ans << endl;
}
//IDEAS
//binary search on min num of days required to reach destination
//can do this since if d days achieveable, then x < d achieveable:
//for last d-x days, ship moves opposite direction of weather
//weather is periodic, so find net change in x and y directions for a cycle
//simulate weather over x days to check, use cycles to make checking faster