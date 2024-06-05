#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Cow {
    ll c, m, waitTime;
};

ll n, cookieTime, muffinTime;
vector<Cow> cows;

//valid function for the binary seach, checks if cost number of moonies is valid
bool valid(ll cost){
    //cout << cookieTime << " " << muffinTime << endl;
    //lo and hi for amount of moonies spent on reducing muffinTime
    double lo = max((ll) 0 , cost-cookieTime), hi = min(muffinTime , cost);
    //cout << lo << " " << hi << endl;
    //iterate over each cow and update lo and hi values
    for(auto cow : cows){
        ll num = cow.waitTime + cow.c*cost - cow.c*cookieTime - cow.m*muffinTime;
        ll den = cow.c - cow.m;
        //cout << "NUMERATOR " << num << " DENOMINATOR " << den << endl;
        //if denominator negative, inequality flips and lo value raised
        if(den < 0) lo = max(lo , (double)num / den);
        //if denominator positive, inequality doesn't flip and hi value lowered
        else if(den > 0) hi = min(hi , (double)num / den);
        //you can't have 0 <= a negative number, so return false
        else if(den == 0 && num < 0) return false;
        //do nothing in the regular case where a_i = b_i
        //cout << lo << " " << hi << endl;
    }
    //checking if the range for moonies spent to decrease muffinTime has atleast one integer value in it
    if(lo > hi || ceil(lo) >= muffinTime || (ll)lo == (ll)hi && (ll)lo != lo) return false;
    //making sure cookieTime is NOT less than one
    if((ll)(cookieTime - (cost - hi)) < 1) return false;
    return true;
}

//lower bound custom binary seach function
ll binarySearch(ll lo , ll hi){
    //cout << lo << " " << hi << endl;
    hi++;
    while(lo < hi){
        //mid is the number of moonies we are checking if valid
        ll mid = lo + (hi - lo)/2;
        //cout << "CHECKING MID: " << mid << endl;
        if(valid(mid)) hi = mid;
        else lo = mid + 1;
    }
    return lo;
}

//main solve function
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

    //solve for each test case
    ll t; cin >> t;
    while(t--){
        solve();
    }
}