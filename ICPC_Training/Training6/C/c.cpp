#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("input.in", "r", stdin);

    string s;
    map<string, int> votes;
    while(s != "***"){
        cin >> s;
        if(s == "***") break;
        votes[s]++;
    }

    int maxVotes = 0;
    string winner;
    bool multiple = false;
    for(auto& p : votes){
        if(p.second > maxVotes){
            maxVotes = p.second;
            winner = p.first;
            multiple = false;
        }
        else if(p.second == maxVotes) multiple = true;
    }

    
}