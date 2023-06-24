#include <bits/stdc++.h>
using namespace std;

int n, m, c;
vector<int> cowArrivalTimes;

bool validMaxTime(int maxTime){
    int totalBuses = 1;
    int curBusCows = 1;
    int firstCowArrival = cowArrivalTimes[0];
    for(int i=1; i<n; i++){
        if(cowArrivalTimes[i] - firstCowArrival > maxTime || curBusCows == c){
            firstCowArrival = cowArrivalTimes[i];
            totalBuses++; curBusCows = 1;
        }
        else curBusCows++;
        //this maxTime would require more buses than we have
        if(totalBuses > m){return false;}
    }
    //all of the cows were successfully placed
    //into the buses such that the maxTime was not exceeded
    return true;
}

int binarySearch(int lo, int hi){
    hi++;
    while(lo < hi){
        int mid = lo + (hi - lo)/2;
        if(validMaxTime(mid)){
            hi = mid;
        }
        else{
            lo = mid+1;
        }
    }
    return lo;
}

int main(){
    freopen("convention.in" , "r" , stdin);
    freopen("convention.out" , "w" , stdout);

    cin >> n >> m >> c;
    cowArrivalTimes.resize(n);
    for(int i=0; i<n; i++){
        cin >> cowArrivalTimes[i];
    }

    sort(cowArrivalTimes.begin() , cowArrivalTimes.end());

    cout << binarySearch(0 , cowArrivalTimes[n-1] - cowArrivalTimes[0]) << endl;

    //given the maximum waiting time for a cow
    //determine if this time is achievable
    //otherwise binary search for best time

    //greedy for a given maximum waiting time
    //fill up buses while this waiting time is not exceeded
    //otherwise starting filling next bus

}

//UNFINISHED