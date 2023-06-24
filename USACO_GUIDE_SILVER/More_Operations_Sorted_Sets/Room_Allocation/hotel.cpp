#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("hotel.in" , "r" , stdin);
    int n; cin >> n;
    vector<array<int , 3>> times(n);
    vector<int> roomForPerson(n);
    priority_queue<pair<int , int>> departureTimes;
    for(int i=0; i<n; i++){
        cin >> times[i][0] >> times[i][1];
        times[i][2] = i;
    }
    sort(times.begin() , times.end());

    int rooms = 0, cur_room;
    for(int i=0; i<n; i++){
        if(!departureTimes.empty() && -departureTimes.top().first < times[i][0]){
            //cout << "CHANGING ROOM " << i << " DEPARTURE TIME " << departureTimes.top().first << " " << rooms << endl;
            cur_room = departureTimes.top().second; departureTimes.pop();
            departureTimes.push(make_pair(-times[i][1] , cur_room));
            roomForPerson[times[i][2]] = cur_room;
            //cout << "CHANGING ROOM " << i << " DEPARTURE TIME " << departureTimes.top().first << " " << rooms << endl;
        }
        else{
            departureTimes.push(make_pair(-times[i][1] , ++rooms));
            roomForPerson[times[i][2]] = rooms;
            //cout << "ADDING ROOM " << i << " " << rooms << endl;
        }
    }

    cout << rooms << endl;
    for(int i=0; i<n; i++){
        cout << roomForPerson[i] << " ";
    }
}