#include <bits/stdc++.h>
using namespace std;

int firstOcc[8];

int main(){
    
    freopen("div7.in" , "r" , stdin);
    freopen("div7.out" , "w" , stdout);

    fill(firstOcc, firstOcc+8, -1);

    int n, tot=0, maxCows = 0; cin >> n;
    for(int i=0; i<n; i++){
        int id; cin >> id;
        tot += id; tot %= 7;
        //cout << tot << endl;
        if(firstOcc[tot] == -1) firstOcc[tot] = i;
        maxCows = max(maxCows, i - firstOcc[tot]);
    }

    cout << maxCows << endl;
    return 0;

}