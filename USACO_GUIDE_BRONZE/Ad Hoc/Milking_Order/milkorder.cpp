#include <bits/stdc++.h>
using namespace std;

int n , m , k;
vector<pair<bool , int>> usedCows;
vector<int> line;
vector<int> structure;

bool valid(){
    int pos = n , cur = m-1;
    while(pos != 0 && cur != -1){
        if(usedCows[structure[cur]].first) {
            pos = usedCows[structure[cur]].second;
            cur--;
        }
        else if(line[pos] == 0) cur--;
        pos--;
    }
    if(pos == 0 && cur != -1) return false;
    return true;
}

int main(){
    freopen("milkorder.in" , "r" , stdin);
    freopen("milkorder.out" , "w" , stdout);

    cin >> n >> m >> k;
    usedCows.resize(n+1);
    line.resize(n+1);

    bool insideStruct = false;
    int Onepos = 0;

    int cow , pos;
    for(int i=0; i<m; i++){
        cin >> cow;
        structure.push_back(cow);
        if (cow == 1){insideStruct = true; Onepos = i+1;}
    }

    for(int i=0; i<k; i++){
        cin >> cow >> pos;
        if(cow == 1){cout << pos << endl; return 0;}
        line[pos] = cow;
        usedCows[cow].first = true;
        usedCows[cow].second = pos;
    }

    if(insideStruct){
        int curr = 0 , used = 0;
        while(used != Onepos){
            curr++;
            if(usedCows[structure[used]].first){
                while(line[curr] != structure[used]) curr++;
                used++;
            }
            else if(line[curr] == 0) used++;
        }
        cout << curr << endl; return 0;
    }

    for(int i=1; i<=n; i++){
        if(line[i] != 0) continue;
        line[i] = 1;
        if(valid()){
            cout << i << endl; return 0;
        }
        line[i] = 0;
    }

    // for(auto x : line){
    //     cout << x << " ";
    // }
    // cout << endl; return 0;
}

/*
 * Notes
 * Does NOT pass test case #7 for some reason...
 * 
 */