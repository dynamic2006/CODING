#include <bits/stdc++.h>
using namespace std;

int fromchar(char c){
    if(islower(c)) return 26 + c - 'a';
    return c - 'A';
}

int cmap[52] , indeg[52];
bool visited[52];

int solve(){
    string s1, s2; cin >> s1 >> s2;
    
    if(s1 == s2) return 0;

    fill(cmap, cmap+52, -1);
    fill(visited, visited+52, false);
    fill(indeg, indeg+52, 0);

    int len = s1.size();

    set<int> distinct;

    for(int i=0; i<len; i++){
        int from = fromchar(s1[i]) , to = fromchar(s2[i]);
        distinct.insert(to);
        if(cmap[from] == -1){
            cmap[from] = to;
            indeg[to]++;
        }
        else if(cmap[from] != to) return -1;
    }

    if(distinct.size() == 52) return -1;

    int ans = 0;

    for(int i=0; i<52; i++){
        if(cmap[i] == i) cmap[i] = -1;
    }

    for(int i=0; i<52; i++){
        if(visited[i]) continue;
        if(cmap[i] == -1) continue;

        vector<int> cycle;
        bool pureCycle = true;
        int ci = i; // copy of i

        while(true){
            if(cmap[ci] == -1) break;

            bool cyclic = false;
            for(int j=0; j < cycle.size(); j++){
                if(ci == cycle[j]){
                    cyclic = true;
                    if(pureCycle) ans++;
                    break;
                }
            }

            if(cyclic) break;
            if(visited[ci]) break;
            visited[ci] = true;
            cycle.push_back(ci);
            ans++;
            if(indeg[ci] > 1) pureCycle = false;
            ci = cmap[ci];
        }
    }

    return ans;

}

int main(){
    //freopen("p1.in" , "r" , stdin);

    int t; cin >> t;
    while(t--){
        cout << solve() << endl;
    }
}