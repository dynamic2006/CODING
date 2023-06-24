#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("measurement.in" , "r" , stdin);
    freopen("measurement.out" , "w" , stdout);

    int n, g; cin >> n >> g;
    map<int , int> cows; //how much milk each cow produces
    //we need to keep track of how many cows have largest output
    map<int , int> cowOutputs; cowOutputs[g] = 10e9;

    vector<array<int , 3>> entries(n);
    for(int i=0; i<n; i++){
        //[0] is day, [1] is cow, [2] is change
        cin >> entries[i][0] >> entries[i][1] >> entries[i][2];
        cows[entries[i][1]] = g;
    }
    sort(entries.begin() , entries.end());//sort by day

    int changes = 0, curCount = 0, prevCount = 0;
    bool was_top = false, is_top = false;
    for(int i=0; i<n; i++){
        //pre-check
        if(cows[entries[i][1]] == prev(cowOutputs.end())->first){was_top = true;}
        else{was_top = false;}
        prevCount = cowOutputs[prev(cowOutputs.end())->first];
        cowOutputs[cows[entries[i][1]]]--;
        if(cowOutputs[cows[entries[i][1]]] <= 0){
            cowOutputs.erase(cows[entries[i][1]]);
        }

        cows[entries[i][1]] += entries[i][2];
        cowOutputs[cows[entries[i][1]]]++;

        //post-check
        if(cows[entries[i][1]] == prev(cowOutputs.end())->first){is_top = true;}
        else{is_top = false;}
        curCount = cowOutputs[prev(cowOutputs.end())->first];
        if(was_top != is_top || curCount != prevCount) changes++;
    }

    cout << changes << endl;
}