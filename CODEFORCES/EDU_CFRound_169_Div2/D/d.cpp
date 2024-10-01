#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MAXNUM = 1e9;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("d.in", "r", stdin);

    int t; cin >> t;
    while(t--){
        int n, q; cin >> n >> q;
        vector<string> portals(n);
        for(int i=0; i<n; i++) cin >> portals[i];
        vector<vector<pair<int, int>>> closestPortals(n, vector<pair<int, int>>(6));

        vector<string> idxMapPortal = {"BG", "BR", "BY", "GR", "GY", "RY"};
        map<string, int> portalMapIdx;
        portalMapIdx["BG"] = 0;
        portalMapIdx["BR"] = 1;
        portalMapIdx["BY"] = 2;
        portalMapIdx["GR"] = 3;
        portalMapIdx["GY"] = 4;
        portalMapIdx["RY"] = 5;

        vector<int> nearestPortalIdx(6, -1);
        for(int i=0; i<n; i++){
            nearestPortalIdx[portalMapIdx[portals[i]]] = i;
            for(int j=0; j<6; j++){
                closestPortals[i][j].first = nearestPortalIdx[j];
            }
        }

        nearestPortalIdx = vector<int>(6, -1);
        for(int i=n-1; i>=0; i--){
            nearestPortalIdx[portalMapIdx[portals[i]]] = i;
            for(int j=0; j<6; j++){
                closestPortals[i][j].second = nearestPortalIdx[j];
            }
        }

        for(int x=0; x<q; x++){
            int a, b; cin >> a >> b;
            if(a>b) swap(a,b);
            a--; b--;
            int minDist = MAXNUM;

            if(portals[a][0] == portals[b][0] || portals[a][0] == portals[b][1] ||
            portals[a][1] == portals[b][0] || portals[a][1] == portals[b][1]){
                cout << b-a << endl;
                continue;
            }
            
            //test valid left 6 nearest portals for b
            for(int j=0; j<6; j++){
                if(idxMapPortal[j][0] != portals[b][0] && idxMapPortal[j][0] != portals[b][1] &&
                idxMapPortal[j][1] != portals[b][0] && idxMapPortal[j][1] != portals[b][1]) continue;
                else if(idxMapPortal[j] == portals[b] || closestPortals[b][j].first == -1) continue;
                else minDist = min(minDist, b-closestPortals[b][j].first + abs(closestPortals[b][j].first - a));
            }
            //test valid right 6 nearest portals for a
            for(int j=0; j<6; j++){
                if(idxMapPortal[j][0] != portals[a][0] && idxMapPortal[j][0] != portals[a][1] &&
                idxMapPortal[j][1] != portals[a][0] && idxMapPortal[j][1] != portals[a][1]) continue;
                else if(idxMapPortal[j] == portals[a] || closestPortals[a][j].second == -1) continue;
                else minDist = min(minDist, closestPortals[a][j].second-a + abs(closestPortals[a][j].second - b));
            }
            if(minDist == MAXNUM) cout << -1 << endl;
            else cout << minDist << endl;
        }

    }
}