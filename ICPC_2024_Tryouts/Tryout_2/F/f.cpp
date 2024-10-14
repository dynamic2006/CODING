#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
vector<pair<int, int>> intervals;
vector<pair<int, int>> newIntervals;

//to check if time is valid
//try extending each interval backwards first
//then extend forward
//if time length not achieveable without overlap then return false
//else return true
bool valid(int time)
{
    vector<pair<int, int>> tempIntervals(n);
    for(int i=0; i<n; i++){
        // cout << "check 1" << endl;
        tempIntervals[i] = intervals[i];
        // cout << "check 2" << endl;
        if(intervals[i].second - intervals[i].first >= time) continue;
        else{
            // cout << "check 1" << endl;
            if(i != 0){
                //try extending backwards
                // cout << "check 1" << endl;
                tempIntervals[i].first = tempIntervals[i-1].second;
            }
            if(tempIntervals[i].second - tempIntervals[i].first < time){
                //try extending forwards
                // cout << "check 1" << endl;
                if(i != n-1) tempIntervals[i].second = min(intervals[i+1].first, tempIntervals[i].first + time);
            }
        }
        if(tempIntervals[i].second - tempIntervals[i].first < time) return false;
    }

    newIntervals = tempIntervals;
    return true;
}

int binarySearch(int lo, int hi)
{
    lo--;
    while(lo<hi){
        int mid = lo + (hi-lo+1)/2;
        // cout << "CHECK1" << endl;
        if(valid(mid)) lo = mid;
        else hi = mid-1;
        // cout << "CHECK2" << endl;
    }
    return lo;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.in", "r", stdin);

    cin >> n;
    intervals = vector<pair<int, int>>(n);
    for(int i=0; i<n; i++){
        string start, sep, end; cin >> start >> sep >> end;
        // cout << start << " hypen here " << end << endl;
        int startTime = (start[0] - '0')*600 + (start[1] - '0')*60 + (start[3] - '0')*10 + (start[4] - '0');
        int endTime = (end[0] - '0')*600 + (end[1] - '0')*60 + (end[3] - '0')*10 + (end[4] - '0');
        intervals[i] = {startTime, endTime};
    }
    newIntervals = intervals;

    // cout << "CHECK" << endl;
    binarySearch(0, 480);
    // cout << "CHECK" << endl;

    for(int i=0; i<n; i++){
        int startHrs = newIntervals[i].first/60;
        int startMin = newIntervals[i].first - startHrs*60;
        int endHrs = newIntervals[i].second/60;
        int endMin = newIntervals[i].second - endHrs*60;
        if(startMin < 10){
            cout << startHrs << ":0" << startMin;
        }
        else cout << startHrs << ":" << startMin;
        cout << " - ";
        if(endMin < 10){
            cout << endHrs << ":0" << endMin;
        }
        else cout << endHrs << ":" << endMin;
        cout << endl;
    }

}