#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll MAXNUM = 1e18;

vector<pair<ll, bool>> a;
ll n, k;

bool valid(ll med)
{
    ll numsAbove = 0;
    ll tempK = k;
    for(ll i=n-2; i>=0; i--){
        if(a[i].first >= med) numsAbove++;
        else if(tempK >= med-a[i].first && a[i].second){
            tempK -= (med-a[i].first);
            numsAbove++;
        }
    }
    if(numsAbove > (n-1)/2) return true;
    else return false;
}

ll binarySearch(ll lo, ll hi)
{
    lo--;
    while(lo<hi){
        ll mid = lo+(hi-lo+1)/2;
        if(valid(mid)) lo=mid;
        else hi = mid-1;
    }
    return lo;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("c.in", "r", stdin);

    int t; cin >> t;
    while(t--){
        cin >> n >> k;
        a = vector<pair<ll, bool>>(n);
        for(ll i=0; i<n; i++) cin >> a[i].first;
        for(ll i=0; i<n; i++) cin >> a[i].second;
        sort(a.begin(), a.end());

        //if largest a[i] has b[i]=1, then ans is simple
        if(a[n-1].second){
            ll ans = a[n-1].first + k;
            ll medIdx = (n-2)/2;
            ans += a[medIdx].first;
            cout << ans << endl;
            continue;
        }

        //otherwise, largest a[i] has b[i]=0
        //so check this number and largest a[i] with b[i]=1

        //checking largest a[i] with b[i]=1
        ll ans1 = 0;
        for(ll i=n-1; i>=0; i--){
            if(a[i].second){
                ans1 = a[i].first + k;
                if(i < n/2) ans1 += a[n/2].first;
                else ans1 += a[(n-2)/2].first;
                break;
            }
        }

        // cout << "ANS1 " << ans1 << endl;

        //checking largest a[i] (b[i]=0)
        ll ans2 = a[n-1].first;
        ll maxMed = binarySearch(1, MAXNUM);
        ans2 += maxMed;

        // cout << "MAXMED " << maxMed << endl;

        cout << max(ans1, ans2) << endl;

    }
}