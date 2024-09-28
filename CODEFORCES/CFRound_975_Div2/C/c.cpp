#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, k;
ll sum;

bool valid(ll len)
{
    ll rem = sum%len;
    if(k >= len - rem) return true;
    return false;
}

ll binarySearch(ll lo, ll hi)
{
    hi++;
    while(lo<hi){
        ll mid = lo + (hi-lo)/2;
        if(valid(mid)) hi = mid;
        else lo = mid+1;
    }
    return lo;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("input.in", "r", stdin);

    int t; cin >> t;
    while(t--){
        cin >> n >> k;
        sum = 0;
        vector<ll> a(n);
        for(int i=0; i<n; i++){
            cin >> a[i];
            sum += a[i];
        }

        ll minLen = binarySearch(*max_element(a.begin(), a.end()), sum);
        cout << "MINLEN" << minLen << endl;
        cout << min((ll)n, (sum+k)/minLen) << endl;
    }

}