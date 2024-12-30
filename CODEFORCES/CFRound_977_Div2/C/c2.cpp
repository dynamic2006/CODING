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
        int n, m, q; cin >> n >> m >> q;
        map<int, int> reorder;
        vector<int> a(n), b(m);
        vector<set<int>> occs(n, set<int>());
        for(int i=0; i<n; i++){
            cin >> a[i];
            reorder[a[i]] = i;
            occs[i].insert(m);
        }
        for(int i=0; i<m; i++){
            cin >> b[i];
            b[i] = reorder[b[i]];
            occs[b[i]].insert(i);
        }

        int badCount = 0;
        vector<bool> inOrder(n, true);
        for(int i=1; i<n; i++){
            if(*occs[i].begin() < *occs[i-1].begin()){
                inOrder[i] = false;
                badCount++;
            }
        }

        if(badCount == 0) cout << "YA" << endl;
        else cout << "TIDAK" << endl;

        for(int i=0; i<q; i++){
            int x, y; cin >> x >> y;
            occs[b[x-1]].erase(x-1);

            if(b[x-1] > 0){
                if(*occs[b[x-1]].begin() >= *occs[b[x-1]-1].begin()){
                    if(!inOrder[b[x-1]]) badCount--;
                    inOrder[b[x-1]] = true;
                }
                else{
                    if(inOrder[b[x-1]]) badCount++;
                    inOrder[b[x-1]] = false;
                }
            }

            if(b[x-1] < n-1){
                if(*occs[b[x-1]+1].begin() >= *occs[b[x-1]].begin()){
                    if(!inOrder[b[x-1]+1]) badCount--;
                    inOrder[b[x-1]+1] = true;
                }
                else{
                    if(inOrder[b[x-1]+1]) badCount++;
                    inOrder[b[x-1]+1] = false;
                }
            }

            b[x-1] = reorder[y];
            occs[b[x-1]].insert(x-1);

            if(b[x-1] > 0){
                if(*occs[b[x-1]].begin() >= *occs[b[x-1]-1].begin()){
                    if(!inOrder[b[x-1]]) badCount--;
                    inOrder[b[x-1]] = true;
                }
                else{
                    if(inOrder[b[x-1]]) badCount++;
                    inOrder[b[x-1]] = false;
                }
            }

            if(b[x-1] < n-1){
                if(*occs[b[x-1]+1].begin() >= *occs[b[x-1]].begin()){
                    if(!inOrder[b[x-1]+1]) badCount--;
                    inOrder[b[x-1]+1] = true;
                }
                else{
                    if(inOrder[b[x-1]+1]) badCount++;
                    inOrder[b[x-1]+1] = false;
                }
            }

            // cout << badCount << endl;

            if(badCount == 0) cout << "YA" << endl;
            else cout << "TIDAK" << endl;

        }

    }
}