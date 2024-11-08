#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.in", "r", stdin);

    int n, r; cin >> n >> r;
    map<int, int> pts;
    for(int i=0; i<n; i++){
        int a; cin >> a;
        pts[a]++;
    }

    vector<int> coords, occs;
    for(auto &p : pts){
        coords.push_back(p.first);
        occs.push_back(p.second);
    }

    vector<int> ans;
    int ptsIntact = n;
    while(ptsIntact > 0){
        //then explosion ends at coords[right]
        //explosion originates at coords[right] - r
        //explosion reaches left to coords[right] - 2r
        int maxPtsHit = 0, curPtsHit = 0;
        int bestCenter = coords[0] - r;
        int bestleft = bestCenter - r, bestright = bestCenter + r;
        int left = 0, right = 0;
        while(right < coords.size()){
            while(coords[right] > coords[left] + 2*r){
                curPtsHit -= occs[left++];
            }
            curPtsHit += occs[right];
            
            if(curPtsHit > maxPtsHit){
                maxPtsHit = curPtsHit;
                bestCenter = coords[right] - r;
                bestleft = left;
                bestright = right;
            }

            right++;
        }
        for(int i=bestleft; i<=bestright; i++){
            occs[i] = 0;
        }
        ptsIntact -= maxPtsHit;
        ans.push_back(bestCenter);
    }

    cout << ans.size() << endl;
    for(auto x : ans) cout << x << " ";
    cout << endl;

}