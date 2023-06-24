#include <bits/stdc++.h>
using namespace std;

//map holds max pieces wood can be divided into
//for a given double ratio -- update this
map<double, int> lastRatioPieces;
map<char, double> counts;

void solve(){
    int n; cin >> n;
    string letters; cin >> letters;

    lastRatioPieces.clear();
    counts.clear();
    
    for(int i=0; i<n; i++){
        counts[letters[i]]++;
        if(counts['K'] == 0){
            cout << (int)counts['D'] << " ";
            continue;
        }
        double ratio = counts['D'] / counts['K'];
        cout << 1 + lastRatioPieces[ratio]++ << " ";
    }

    cout << endl;

}

int main(){

    //freopen("wood.in" , "r" ,  stdin);

    int t; cin >> t;
    while(t--){
        solve();
    }

}