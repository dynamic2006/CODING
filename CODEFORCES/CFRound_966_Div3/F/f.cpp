#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("f.in", "r", stdin);

    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        vector<pair<int, int>> rects(n);
        for(int i=0; i<n; i++){
            int a, b; cin >> a >> b;
            rects[i].second = min(a,b);
            rects[i].first = min(a,b) + max(a,b);
        }
        sort(rects.begin(), rects.end());

        ll ops = 0;
        int unusedRect = -1;
        for(int i=n-1; i>=0; i--){
            if(k >= rects[i].first){
                k -= rects[i].first;
                ops += (rects[i].first);
            }
            else if(unusedRect == n) unusedRect = i;
            else if(rects[i].second < rects[unusedRect].second) unusedRect = i;
        }
        if(k > 0 && unusedRect == -1){
            cout << -1 << endl;
            continue;
        }



        ll ops = 0;
        for(int i=0; i<n; i++){
            if(rects[i].second < rects[i].first){
                
            }
            else{
                int sub = min(rects[i].second+1, k);
            }
            int minSide = min(rects[i].first, rects[i].second);
            int sub = min(rects[i].second+1, k);
            k -= sub;
            if(sub == rects[i].second+1) ops += sub-1;
            else ops += sub;
        }
        if(k > 0) cout << -1 << endl;
        else cout << ops << endl;
    }
}