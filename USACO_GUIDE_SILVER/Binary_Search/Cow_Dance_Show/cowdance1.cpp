#include <bits/stdc++.h>
using namespace std;

int n, tmax;
vector<int> durations;

//checking function
bool valid(int k)
{
    priority_queue<int> stage;
    for(int i=0; i<k; i++){
        stage.push(-durations[i]); //want to get smallest val
    }
    for(int i=k; i<n; i++){
        int endTime = stage.top();
        endTime -= durations[i];
        stage.pop();
        stage.push(endTime);
    }

    int finalTime = -1;
    while(!stage.empty()){
        finalTime = max(finalTime, -stage.top());
        stage.pop();
    }

    if(finalTime <= tmax) return true;
    return false;
}

//binarySearch for smallest k possible
int binarySearch(int lo, int hi)
{
    hi++;
    while(lo < hi){
        int mid = lo + (hi-lo)/2;
        if(valid(mid)) hi = mid;
        else lo = mid+1;
    }
    return lo;
}

int main()
{
    freopen("cowdance.in", "r" , stdin);
    freopen("cowdance.out", "w" , stdout);

    cin >> n >> tmax;
    durations.resize(n);
    for(int i=0; i<n; i++){
        cin >> durations[i];
    }

    int ans = binarySearch(1, n);
    cout << ans << endl;
}

//IDEAS
//binary search on k to find min k
//sliding window over cows
//update min end time with priority queue
//check if final end time (max num in pq) < T_max
