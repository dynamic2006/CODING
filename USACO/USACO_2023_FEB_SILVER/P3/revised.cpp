#include <bits/stdc++.h>
using namespace std;

struct Flight {
    int curPort, toPort, leaveTime, arrTime;
    Flight(int curPort, int toPort, int leaveTime, int arrTime){
        this->arrTime = arrTime;
        this->curPort = curPort;
        this->leaveTime = leaveTime;
        this->toPort = toPort;
    }
};

bool cmp(Flight& a, Flight& b){
    return (a.leaveTime < b.leaveTime);
}

const int MAXN = 2*1e5;
int n, m;
int arrTimes[MAXN+1] , layovers[MAXN+1];
bool visited[MAXN+1];
map<int , vector<Flight>> flights;

void dfs(int start, int curTime){
    visited[start] = true;
    for(auto flight : flights[start]){
        if(curTime > flight.leaveTime) continue;
        if(!visited[flight.toPort] || arrTimes[flight.toPort] > flight.arrTime){
            arrTimes[flight.toPort] = flight.arrTime;
            dfs(flight.toPort , flight.arrTime + layovers[flight.toPort]);
        }
    }
}

int main(){

    fill(arrTimes , arrTimes + MAXN+1 , -1);

    //freopen("p3.in" , "r" , stdin);

    cin >> n >> m;
    for(int i=0; i<m; i++){
        int curPort, toPort, leaveTime, arrTime;
        cin >> curPort >> leaveTime >> toPort >> arrTime;
        flights[curPort].push_back(Flight(curPort, toPort, leaveTime, arrTime));
    }
    for(int i=0; i<n; i++){
        cin >> layovers[i+1];
    }

    for(auto x : flights){
        sort(x.second.begin() , x.second.end() , cmp);
    }

    //time to dfs!
    //only visit an airport if not visited before
    //OR if visiting it will decrease the arrivalTime

    arrTimes[1] = 0;
    dfs(1, 0);

    for(int i=1; i<=n; i++){
        if(visited[i]) cout << arrTimes[i] << endl;
        else cout << -1 << endl;
    }
    return 0;

}