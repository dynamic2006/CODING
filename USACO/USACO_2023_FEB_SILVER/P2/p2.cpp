#include <bits/stdc++.h>
using namespace std;

int main(){

    freopen("p2.in" , "r" , stdin);

    //idea
    //put grazings in a set sorted by time
    //go through each cow -- if it can reach
    //the most recent prev and next grazing
    //then they are NOT innocent
    //all other cows are innocent

    unordered_map<long long , pair<long long , long long>> grazingLocations;
    set<long long> grazings;

    long long g, n; cin >> g >> n;
    for(long long i=0; i<g; i++){
        long long x, y, time; cin >> x >> y >> time;
        grazings.insert(time);
        grazingLocations[time] = {x , y};
    }

    long long notInnocent = 0;
    for(long long i=0; i<n; i++){
        long long x, y, time; cin >> x >> y >> time;
        
        //check if the cow can reach the previous grazing
        bool canReachPrev = true;
        if(time > *grazings.begin()){
            set<long long>::iterator previous = prev(grazings.upper_bound(time));
            long long sqrdist = (x - grazingLocations[*previous].first)*(x - grazingLocations[*previous].first) + (y - grazingLocations[*previous].second)*(y - grazingLocations[*previous].second);
            if((time - *previous)*(time - *previous) >= sqrdist) canReachPrev = true;
            else canReachPrev = false;
        }

        bool canReachNext = true;
        if(time < *grazings.rbegin()){
            set<long long>::iterator next = grazings.upper_bound(time);
            long long sqrdist = (x - grazingLocations[*next].first)*(x - grazingLocations[*next].first) + (y - grazingLocations[*next].second)*(y - grazingLocations[*next].second);
            if((*next - time)*(*next - time) >= sqrdist) canReachNext = true;
            else canReachNext = false;
        }

        if(canReachNext && canReachPrev){
            notInnocent++;
            //cout << x << " " << y << " " << time << endl;
        }

    }
    
    cout << n - notInnocent << endl;
    return 0;


}