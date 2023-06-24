#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("cellular.in" , "r" , stdin);
    int n, m, r = 0; cin >> n >> m;
    vector<int> cities(n), towers(m);
    for(int i=0; i<n; i++){
        cin >> cities[i];
    }
    for(int i=0; i<m; i++){
        cin >> towers[i];
    }

    //iterate over all cities and find max needed dist
    //keep two pointers for the tower(s) closest to cur city
    vector<int>::iterator left = towers.begin() , right = left+1;
    for(int city : cities){
        while(*right < city && right != towers.end()){
            right++; left++;
        }
        int min_dist = abs(city - *left); //this is the left distance
        if(right != towers.end()){min_dist = min(min_dist , *right - city);}
        r = max(r , min_dist);
    }
    cout << r << endl;
}