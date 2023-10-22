#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, c;
vector<ll> minutes;

bool valid(int time, int minBefore){
    ll maxBefore = 0;
    for(ll i=0; i<n; i++){
        maxBefore += ceil((time / minutes[i]));
    }
    //Problem might be here??
    if(minBefore <= maxBefore) return true;
    return false;
}

ll binarySearch(ll lo, ll hi, ll M1){
    hi++;
    while(lo<hi){
        ll mid = lo + (hi-lo)/2;
        ll time = mid * M1;
        if(valid(time, mid)) hi = mid;
        else lo = mid + 1;
    }
    return lo;
}

int main() {

    //freopen("p4.in" , "r" , stdin);

    cin >> n >> c;
    for(int i=0; i<n; i++){
        ll t; cin >> t;
        minutes.push_back(t);
    }

    //binary search on the cows before bessie
    //lo = C_i - 1
    //hi = C_i + N + 1

    ll cowsBefore = binarySearch(c - 1, c + n, minutes[0]);
    cout << cowsBefore - (c-1) << endl;

}