#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<pair<long long , bool>> intervalPoints;

bool valid(int d){
    //put a cow at the current spot
    //then the next cow's location must be atleast d away
    //so make an iterator to go thru intervalPoints, increment it while it is too small
    //if the iterator is pointing to a second false point -- set cur cow loc to this value
    //if the iterator is pointing to a second true value -- set cur cow loc to the +d value
    //keep going while there are cows to use and the iterator hasn't reached the end

    int usedCows = 1;
    long long nextClosestPos = intervalPoints[0].first + d;
    auto it = intervalPoints.begin();
    while(usedCows < n){
        while(it->first < nextClosestPos){
            it++;
            if(it == intervalPoints.end()) return false;
        }

        if(it->second){
            nextClosestPos += d;
        }
        else{
            nextClosestPos = it->first + d;
        }
        usedCows++;
    }
    return true;

}

int binarySearch(int lo, int hi){
    lo--;
    while(lo < hi){
        int mid = lo + (hi - lo + 1)/2;
        if(valid(mid)){
            lo = mid;
        }
        else{
            hi = mid - 1;
        }
    }
    return lo;
}

int main(){
    freopen("socdist.in" , "r" , stdin);
    freopen("socdist.out" , "w" , stdout);

    cin >> n >> m; intervalPoints.resize(2*m);
    for(int i=0; i<2*m; i+=2){
        //note that when sorted, points with the same first value
        //the false second val with come before the true second val
        //second -- true if the point is a endpoint, false if it is a startpoint
        cin >> intervalPoints[i].first;
        intervalPoints[i].second = false;
        cin >> intervalPoints[i+1].first;
        intervalPoints[i+1].second = true;
    }
    sort(intervalPoints.begin() , intervalPoints.end());

    cout << binarySearch(1 , intervalPoints[m-1].first - intervalPoints[0].first) << endl;


}