#include <bits/stdc++.h>
using namespace std;

int n, tMax;
vector<int> cows;

bool valid(int k){

    priority_queue<int , vector<int> , greater<int>> cowsOnStage;
    for(int i=0; i<k; i++){
        cowsOnStage.push(cows[i]);
    }
    
    int nextCow = k;
    while(nextCow != n){
        cowsOnStage.push(cowsOnStage.top() + cows[nextCow++]);
        cowsOnStage.pop();
    }
    for(int i=1; i<k; i++){
        cowsOnStage.pop();
    }

    if(cowsOnStage.top() > tMax){
        return false;
    }
    return true;

}

int binarySearch(int lo, int hi){
    hi++;
    while(lo < hi){
        int mid = lo + (hi - lo)/2;
        if(valid(mid)){
            hi = mid;
        }
        else{
            lo = mid + 1;
        }
    }
    return lo;
}

int main(){
    freopen("cowdance.in" , "r" , stdin);
    freopen("cowdance.out" , "w" , stdout);

    cin >> n >> tMax; cows.resize(n);
    for(int i=0; i<n; i++){
        cin >> cows[i];
    }

    cout << binarySearch(1, n) << endl;

}