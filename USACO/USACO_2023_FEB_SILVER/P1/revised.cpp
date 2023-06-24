#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Cow {
    ll c, m, waitTime;
};

ll n, cookieTime, muffinTime;
vector<Cow> cows;

bool valid(ll cost){
    //cout << cookieTime << " " << muffinTime << endl;
    double lo = max((ll) 0 , cost-cookieTime), hi = min(muffinTime , cost);
    //cout << lo << " " << hi << endl;
    for(auto cow : cows){
        ll num = cow.waitTime + cow.c*cost - cow.c*cookieTime - cow.m*muffinTime;
        ll den = cow.c - cow.m;
        //cout << "NUMERATOR " << num << " DENOMINATOR " << den << endl;
        if(den < 0) lo = max(lo , (double)num / den);
        else if(den > 0) hi = min(hi , (double)num / den);
        else if(den == 0 && num < 0) return false;
        //cout << lo << " " << hi << endl;
    }
    if(lo > hi || ceil(lo) >= muffinTime || (ll)lo == (ll)hi && (ll)lo != lo) return false;
    if((ll)(cookieTime - (cost - hi)) < 1) return false;
    return true;
}

ll binarySearch(ll lo , ll hi){
    //cout << lo << " " << hi << endl;
    hi++;
    while(lo < hi){
        ll mid = lo + (hi - lo)/2;
        //cout << "CHECKING MID: " << mid << endl;
        if(valid(mid)) hi = mid;
        else lo = mid + 1;
    }
    return lo;
}

void solve(){
    cin >> n >> cookieTime >> muffinTime;
    //cout << n << cookieTime << " " << muffinTime << endl;
    //return;
    cows.clear();
    cows.resize(n);
    for(ll i=0; i<n; i++){
        cin >> cows[i].c >> cows[i].m >> cows[i].waitTime;
    }
    cout << binarySearch(0 , cookieTime + muffinTime) << endl;
}

int main(){
    //freopen("p1.in" , "r" , stdin);

    ll t; cin >> t;
    while(t--){
        solve();
    }
}