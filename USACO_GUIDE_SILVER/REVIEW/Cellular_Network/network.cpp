#include <bits/stdc++.h>
using namespace std;

int main(){

    //freopen("network.in" , "r" , stdin);

    int n, m; cin >> n >> m;
    vector<int> cities(n), towers(m);
    for(int i=0; i<n; i++) cin >> cities[i];
    for(int i=0; i<m; i++) cin >> towers[i];

    vector<int>::iterator l = towers.begin() , r = next(l);
    int radius = -1;
    if(r == towers.end()) r--;
    for(int i=0; i<n; i++){
        //process city at cities[i]
        while(*r < cities[i] && next(r) != towers.end()){
            r++; l++;   
        }
        int minDist = min(abs(*l - cities[i]) , abs(*r - cities[i]));
        radius = max(radius , minDist);
    }
    cout << radius << endl;
    return 0;

}