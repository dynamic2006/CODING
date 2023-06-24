#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> coords , speeds;

bool validTime(double time){
    double lowerBound = 0 , upperBound = 10e9;
    for(int i=0; i<n; i++){
        lowerBound = max(lowerBound , coords[i] - time*speeds[i]);
        upperBound = min(upperBound , coords[i]  + time*speeds[i]);
        if(lowerBound > upperBound) return false;
    }
    return true;
}

double binarySearch(double lo , double hi){
    hi++;
    while(hi - lo > 0.0000001){
        double mid = lo + (hi - lo)/2;
        if(validTime(mid)) hi = mid;
        else lo = mid;
    }
    return lo;
}

int main(){
    //freopen("meeting.in" , "r" , stdin);

    cin >> n;
    coords.resize(n); speeds.resize(n);
    for(int i=0; i<n; i++){
        cin >> coords[i];
    }
    for(int i=0; i<n; i++){
        cin >> speeds[i];
    }
    
    cout << fixed << binarySearch(0 , (10e9)/2) << endl;

}