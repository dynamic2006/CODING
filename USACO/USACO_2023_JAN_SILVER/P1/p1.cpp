#include <bits/stdc++.h>
using namespace std;

void solve(){
    //take int the og and desired strings
    //go over given string and check duplicate vals map to same thing in desired string
    //keep track of each distinct mapping of a char in given to corresponding char in desired
    map<char , int> despos;
    map<char , int> givpos;
    map<char, bool> occurred;
    map<char , char> succ;
    string given, desired; cin >> given >> desired;
    string uniqueGiven, uniqueDesired;
    for(int i=0; i<given.size(); i++){
        if(occurred[given[i]] && desired[i] != succ[given[i]]){
            cout << -1 << endl; return;
        }
        else if(!occurred[given[i]]){
            occurred[given[i]] = true;
            succ[given[i]] = desired[i];
            givpos[given[i]] = i;
            uniqueGiven += given[i];
            despos[despos[i]] = i;
            uniqueDesired += desired[i];
        }
    }

    //now using succ go thru uniqueGiven
    //keep a visited bool array; loop over all letters
    //if not visited, start a dfs -- if there is a cycle add one
    long long ans = 0;
    vector<bool> visited(uniqueGiven.size());
    for(int i=0; i<visited.size(); i++){
        visited[i] = false;
    }
    for(int i=0; i<uniqueGiven.size(); i++){
        if(visited[i]) continue;

        int cur = i;
        while(!visited[cur]){
            visited[cur] = true;
            char curChar = uniqueGiven[cur];
            //cout << curChar << endl;
            char nextChar = succ[uniqueGiven[cur]];
            //cout << nextChar << endl;
            if(curChar == nextChar) continue;
            if(givpos.count(nextChar) == 0) ans++;
            else cur = givpos[nextChar];
            if(visited[cur]) ans++;
        }
    }

    cout << ans << endl; return;
}

int main(){
    freopen("p1.in" , "r" , stdin);

    int t; cin >> t;
    while(t--){
        solve();
    }
}