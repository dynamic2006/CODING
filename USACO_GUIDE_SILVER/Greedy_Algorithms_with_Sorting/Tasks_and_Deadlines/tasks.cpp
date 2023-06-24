#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("tasks.in" , "r" , stdin);

    int n; cin >> n;
    vector<pair<int , int>> tasks(n);
    for(int i=0; i<n; i++){
        cin >> tasks[i].first >> tasks[i].second;
    }
    sort(tasks.begin() , tasks.end());

    long long reward, totalReward = 0 , time = 0;
    for(int i=0; i<n; i++){
        time += tasks[i].first; //add duration to time to get finish time
        reward = tasks[i].second - time;
        totalReward += reward;
    }

    cout << totalReward << endl;
}