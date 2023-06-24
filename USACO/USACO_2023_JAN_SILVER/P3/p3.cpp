#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("p3.in" , "r" , stdin);
    
    int n, total = 0; cin >> n;
    vector<int> passes(n);
    for(int i=0; i<n; i++){
        cin >> passes[i];
        total += passes[i];
    }

    //sum of Ai is less than 10^6 so should be able to simulate it?
    //keep going in certain direction unless there is a 1 next
    //in this case, switch directions is the cur num is greater than 1

    string moves = "";
    int cur = 0, dir = 1;
    while(total != 0){
        if(dir == 1) moves += 'R';
        else moves += 'L';
        passes[cur]--; total--;
        if(cur + dir >= n || cur + dir < 0 || passes[cur + dir] <= 1 && passes[cur] >= 1) dir = -dir;
        else cur += dir;
    }

    cout << moves << endl; return 0;

}