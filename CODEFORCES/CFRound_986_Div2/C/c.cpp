#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.in", "r", stdin);

    int t; cin >> t;
    while(t--){
        int n, m, v; cin >> n >> m >> v;
        ll totalLeftOver = 0;
        vector<int> vals(n);
        vector<ll> prefix(n+1); prefix[0] = 0;
        for(int i=0; i<n; i++){
            cin >> vals[i];
            totalLeftOver += vals[i];
            prefix[i+1] = totalLeftOver;
        }

        int totalSegsLeft = 0;
        vector<int> leftSegs(n), rightSegs(n);
        ll cursum = 0, segs = 0;
        for(int i=0; i<n; i++){
            if(cursum >= v){
                leftSegs[i] = ++segs;
                cursum = vals[i];
            }
            else{
                leftSegs[i] = segs;
                cursum += vals[i];
            }
        }
        if(cursum >= v) segs++;
        totalSegsLeft = segs;
        cursum = 0; segs = 0;
        
        int totalSegsRight = 0;
        for(int i=n-1; i>=0; i--){
            if(cursum >= v){
                rightSegs[i] = ++segs;
                cursum = vals[i];
            }
            else{
                rightSegs[i] = segs;
                cursum += vals[i];
            }
        }
        if(cursum >= v) segs++;
        totalSegsRight = segs;
        cursum = 0; segs = 0;

        if(totalSegsLeft < m && totalSegsRight < m){
            // cout << leftSums[0] << endl;
            cout << -1 << endl;
            continue;
        }

        //for each starting left point, find max ending right point
        ll maxAns = 0;
        int right = -1;
        for(int left=0; left<n; left++){
            while(right < n-1 && leftSegs[left] + rightSegs[right+1] >= m) right++;
            maxAns = max(maxAns, prefix[right+1] - prefix[left]);
        }

        cout << maxAns << endl;
    }
}