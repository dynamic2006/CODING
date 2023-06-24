#include <bits/stdc++.h>
using namespace std;

int n , d , m;
vector<pair<int , int>> jobs;

//for a given number of machines, check if it works
bool valid(int machines){
    priority_queue<int, vector<int> , greater<int>> endTimes;
    for(int i=0; i<machines; i++){
        endTimes.push(jobs[i].first);
    }
    for(int i=machines; i<m; i++){
        int newEndTime = max(endTimes.top() + 1 , jobs[i].first);
        if(newEndTime - jobs[i].first > d) return false;
        endTimes.push(newEndTime);
        endTimes.pop();
    }
    return true;
}

//we want the MINIMUM number of machines, so use first_true
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
    //freopen("job.in" , "r" , stdin);
    
    cin >> n >> d >> m; jobs.resize(m);

    for(int i=0; i<m; i++){
        cin >> jobs[i].first;
        jobs[i].second = i+1;
    }

    sort(jobs.begin() , jobs.end());
    int minMachines = binarySearch(1 , m);

    cout << minMachines << endl;

    vector<string> schedule(n+1);
    priority_queue<int, vector<int> , greater<int>> endTimes;
    for(int i=0; i<minMachines; i++){
        endTimes.push(jobs[i].first);
        schedule[jobs[i].first] += to_string(jobs[i].second) + " ";
    }
    for(int i=minMachines; i<m; i++){
        int newEndTime = max(endTimes.top() + 1 , jobs[i].first);
        schedule[newEndTime] += to_string(jobs[i].second) + " ";
        endTimes.push(newEndTime);
        endTimes.pop();
    }

    for(int i=1; i<=n; i++){
        cout << schedule[i];
        cout << 0 << endl;
    }

}

/*
 * NOTES
 * THIS SOLUTION MISSES (1) TEST CASE
 * overall, the approach is correct but there is a TLE error of ~97 milliseconds on the 19th test case
 * try returning a pair<bool , vector<vector<int>> when redoing this problem
 * note the above adjustment may not fix problem
 */