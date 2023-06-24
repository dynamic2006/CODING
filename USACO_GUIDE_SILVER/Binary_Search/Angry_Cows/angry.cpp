#include <bits/stdc++.h>
using namespace std;

int n , k;
vector<int> balesLocations;

bool validR(int r){
    int curLaunchLocation = balesLocations[0] + r , usedLaunches = 1;
    vector<int>::iterator nextLocation = upper_bound(balesLocations.begin() , balesLocations.end() , curLaunchLocation + r);
    while(nextLocation != balesLocations.end()){
        curLaunchLocation = *nextLocation + r; usedLaunches++;
        if(usedLaunches > k) return false;
        nextLocation = upper_bound(balesLocations.begin() , balesLocations.end() , curLaunchLocation + r);
    }
    return true;
}

int binarySearch(int lo , int hi){
    hi++;
    while(lo < hi){
        int mid = lo + (hi - lo)/2;
        if(validR(mid)){
            hi = mid;
        }
        else{
            lo = mid + 1;
        }
    }
    return lo;
}

int main(){

    freopen("angry.in" , "r" , stdin);
    freopen("angry.out" , "w" , stdout);

    cin >> n >> k; balesLocations.resize(n);
    for(int i=0; i<n; i++){
        cin >> balesLocations[i];
    }
    sort(balesLocations.begin() , balesLocations.end());

    int maxR = ((balesLocations[n-1] + balesLocations[0]) / 2) + 1;

    cout << binarySearch(0 , maxR) << endl;

}

//use coord compression to store indices where there are haybales??
//