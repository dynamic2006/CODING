#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MAXNUM = 1e6;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("freq.in", "r", stdin);

    int n, c; cin >> n >> c;
    vector<int> a(n), diffs(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
        diffs[i] = c - a[i];
    }

    //ans[i].first is cur prefix count
    //ans[i].second.first is cur min prefix
    //ans[i].second.second is cur max answer
    vector<pair<int, pair<int, int>>> ans(MAXNUM+1, {0,{0,0}});
    int zerosFound = 0;
    for(int i=0; i<n; i++){
        int idx = diffs[i] + (MAXNUM/2);
        if(idx == MAXNUM/2){
            //k=0
            // ans[idx].first++;
            // ans[idx].second.second++;
            zerosFound++;
        }
        else{
            ans[idx].second.first = min(ans[idx].second.first, ans[idx].first - zerosFound);
            ans[idx].first++;
            ans[idx].second.second = max(ans[idx].second.second, ans[idx].first - ans[idx].second.first - zerosFound);
        }
    }

    int maxAns = zerosFound;
    for(int i=0; i<=MAXNUM; i++) maxAns = max(maxAns, ans[i].second.second + zerosFound);
    cout << maxAns << endl;
}