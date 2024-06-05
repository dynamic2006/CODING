#include <bits/stdc++.h>
using namespace std;

//converts characters to numbers [0-51]
int fromchar(char c){
    if(islower(c)) return 26 + c - 'a'; // a=26, b=27... z=51
    return c - 'A'; // A=0, B=1... Z=25
}

int cmap[52] , indeg[52];
bool visited[52];

int solve(){
    string s1, s2; cin >> s1 >> s2;
    
    //case where strings are equal already
    if(s1 == s2) return 0;

    fill(cmap, cmap+52, -1);
    fill(visited, visited+52, false);
    //indeg is number of edges going into node
    //a cycle is pure iff every node in it has indeg of 1
    fill(indeg, indeg+52, 0);

    int len = s1.size();

    set<int> distinct;

    for(int i=0; i<len; i++){
        int from = fromchar(s1[i]) , to = fromchar(s2[i]);
        distinct.insert(to);
        //build graph using {cmap} and indeg
        if(cmap[from] == -1){
            cmap[from] = to;
            indeg[to]++;
        }
        //this is an impossible case, a letter cannot go to >1 other letters
        else if(cmap[from] != to) return -1;
    }

    //other impossible case, only works if s1 = s2, checked above
    if(distinct.size() == 52) return -1;

    int ans = 0;

    //chars that map to themselves can be ignored
    for(int i=0; i<52; i++){
        if(cmap[i] == i) cmap[i] = -1;
    }

    for(int i=0; i<52; i++){
        if(visited[i]) continue;
        if(cmap[i] == -1) continue;

        vector<int> cycle;
        bool pureCycle = true;
        int ci = i; // copy of i
        
        //starts at a node and follows edges until it can't anymore
        while(true){
            if(cmap[ci] == -1) break; //reached end of path, nothing more to do

            bool cyclic = false;
            for(int j=0; j < cycle.size(); j++){
                if(ci == cycle[j]){
                    cyclic = true;
                    if(pureCycle) ans++; // need to use an extra character
                    break; // break if you find a cycle
                }
            }

            //break out of path if cyclic or if you visited a node in the cycle already
            if(cyclic) break;
            if(visited[ci]) break;
            visited[ci] = true;
            cycle.push_back(ci);
            ans++;
            if(indeg[ci] > 1) pureCycle = false; //if indeg > 1, NOT a purecycle
            ci = cmap[ci]; //follow edge to next node in path
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