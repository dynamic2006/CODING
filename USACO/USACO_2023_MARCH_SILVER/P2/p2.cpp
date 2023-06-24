#include <bits/stdc++.h>
using namespace std;

vector<string> teams;
vector<int> reps;
vector<int> table;

//NOT FOR FINAL SUBMISSION -- TESTING MY THOUGHT PROCESS
//REFERED TO STACK OVERFLOW FOR LOGIC TO COUNT NUMBER OF ONES
int count(unsigned int x){
    unsigned int c;

    c = x - ((x >> 1) & 033333333333) - ((x >> 2) & 011111111111);
    return ((c + (c >> 3)) & 030707070707) % 63;
}

int main(){

    int maxn = pow(2,18);
    table.resize(maxn);
    for(int i=0; i<maxn; i++){
        table[i] = count(i);
    }

    //freopen("p2.in" , "r" , stdin);

    int c, n; cin >> c >> n;
    for(int i=0; i<n; i++){
        string team; cin >> team;
        int num = 0;
        for(int i=0; i<c; i++) {
            num = (num << 1) | (team[i] == 'H'? 1:0);
        }
        reps.push_back(num);
        teams.push_back(team);
    }

    for(int i=0; i<reps.size(); i++){
        int maxDiff = 0;
        for(int j=0; j<reps.size(); j++){
            if(j == i) continue;
            maxDiff = max(table[reps[i] ^ reps[j]] , maxDiff);
            if(maxDiff == c) break;
        }
        cout << maxDiff << endl;
    }
    return 0;
}