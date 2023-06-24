#include <bits/stdc++.h>
using namespace std;

struct Event{
    int start, end;
};
bool cmp(Event& a, Event& b){
    return(a.end < b.end);
}

int main(){
    //freopen("movie.in" , "r", stdin);
    
    int n; cin >> n;
    vector<Event> events(n);
    for(int i=0; i<n; i++){
        cin >> events[i].start >> events[i].end;
    }
    sort(events.begin() , events.end() , cmp);

    int total = 0, current_end_time = -1;
    for(int i=0; i<n; i++){
        if(events[i].start >= current_end_time){
            current_end_time = events[i].end;
            total++;
        }
    }
    cout << total << endl;
}