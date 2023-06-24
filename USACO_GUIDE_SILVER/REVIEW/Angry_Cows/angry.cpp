#include <bits/stdc++.h>
using namespace std;

int n, k;
set<int> locs;

//check if for a given radius r
//we can explode all the haybales
//greedy approach, go as far as possible
//from the first unexploded haybale
bool valid(int r){
    int usedCows = 0;
    set<int>::iterator curLoc = locs.begin();
    while(usedCows <= k && curLoc != locs.end()){
        usedCows++;
        curLoc = locs.upper_bound(*curLoc + 2*r);
    }
    if(usedCows > k) return false;
    return true;
}

//binary search on the radius
int binarySearch(int lo , int hi){
    hi++;
    while(lo < hi){
        int mid = lo + (hi - lo)/2;
        if(valid(mid)) hi = mid;
        else lo = mid+1;
    }
    return lo;
}

int main(){

    freopen("angry.in" , "r" , stdin);
    freopen("angry.out" , "w" , stdout);

    cin >> n >> k;
    for(int i=0; i<n; i++){
        int loc; cin >> loc;
        locs.insert(loc);
    }

    cout << binarySearch(0 , 1e9) << endl;

}