#include <bits/stdc++.h>
using namespace std;

struct Flight {
    int depTime , toCity , arrTime;
    bool taken = false;
    
    Flight(int depTime , int toCity , int arrTime){
        this->depTime = depTime;
        this->toCity = toCity;
        this->arrTime = arrTime;
    }
};

const int MAXN = 2*1e5;
int arrTimes[MAXN+1] , layovers[MAXN+1];
vector<Flight> flights[MAXN+1];

void dfs(int curCity , int curTime){
    if(arrTimes[curCity] == -1) arrTimes[curCity] = curTime;
    else arrTimes[curCity] = min(arrTimes[curCity] , curTime);

    if(arrTimes[1] < 0) arrTimes[1] = 0;

    curTime += layovers[curCity];

    for(auto f : flights[curCity]){
        if(f.depTime >= curTime){
            if(f.arrTime < arrTimes[f.toCity] || arrTimes[f.toCity] == -1){
                dfs(f.toCity , f.arrTime);
            }
        }
    }
}

int main(){

    fill(arrTimes , arrTimes + MAXN+1 , -1);

    freopen("p3.in" , "r" , stdin);

    int n , m; cin >> n >> m;
    for(int i=0; i<m; i++){
        int c, r, d, s; cin >> c >> r >> d >> s;
        //first is the departure time
        //second is a pair where first is toCity and second is arrTime
        Flight f = Flight(r,d,s);
        flights[c].push_back(f);
    }

    for(int i=1; i<=n; i++) cin >> layovers[i];

    // for(int i=0; i<=n; i++){
    //     for(auto x : flights[i]){
    //         x.taken = true;
    //         cout << i << " " << x.depTime << " " << x.toCity << " " << x.arrTime << " " << x.taken << endl;
    //     }
    // }

    // return 0;

    //dfs from 1
    //only take a flight if:
    //the current time is less than depTime of the flight
    //and you haven't taken the flight before
    //or taking the flight would reduce the arrTime for the arrCity
    //when taking a flight, set curTime to arrTime + layover of the flight

    dfs(1 , -layovers[1]);

    for(int i=1; i<=n; i++){
        cout << arrTimes[i] << endl;
    }
    return 0;



}