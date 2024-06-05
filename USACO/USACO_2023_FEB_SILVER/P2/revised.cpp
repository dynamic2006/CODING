#include <bits/stdc++.h>
using namespace std;

struct Grazing {
    long long x, y;
    Grazing(){
        x = 0, y = 0;
    }
    Grazing(long long x , long long y){
        this->x = x; this->y = y;
    }
};

struct Alibi {
    long long x , y , time;
};

int main(){
    //freopen("p2.in" , "r" , stdin);

    long long g , n; cin >> g >> n;
    map<long long , Grazing> grazingLocations;
    set<long long> grazingTimes;
    vector<Alibi> alibis(n);

    //cout << g << " " << n << " " << n+g << endl;

    for(long long i=0; i<g; i++){
        long long x, y, t; cin >> x >> y >> t;
        grazingTimes.insert(t);
        grazingLocations[t] = Grazing(x , y);
    }
    for(long long i=0; i<n; i++){
        cin >> alibis[i].x >> alibis[i].y >> alibis[i].time;
    }

    //pass through alibis
    //for each alibi, if it can reach grazing at
    //next closest time and previous closest time
    //then cow is NOT innocent

    long long total = 0;
    for(auto a : alibis){
        long long time = a.time;
        if(time <= *prev(grazingTimes.end())){
            //finds next closest grazing time with lower bound
            long long nextTime = *grazingTimes.lower_bound(time);
            Grazing nextGrazing = grazingLocations[nextTime];
            long long nextX = nextGrazing.x, nextY = nextGrazing.y, timeDiff = nextTime - time;
            //cow are not required to travel along grid lines
            //we use the pythagorean thm to check if the cow can get to the next grazing in time
            long long dist = (nextX - a.x)*(nextX - a.x) + (nextY - a.y)*(nextY - a.y);
            if(dist > timeDiff*timeDiff) continue;
        }
        if(time >= *grazingTimes.begin()){
            long long prevTime = *prev(grazingTimes.upper_bound(time));
            Grazing prevGrazing = grazingLocations[prevTime];
            long long prevX = prevGrazing.x, prevY = prevGrazing.y, timeDiff = time - prevTime;
            long long dist = (prevX - a.x)*(prevX - a.x) + (prevY - a.y)*(prevY - a.y);
            if(dist > timeDiff*timeDiff) continue;
        }
        //if you get here, that means the cow is NOT INNOCENT
        total++;

    }

    cout << n - total << endl;
    return 0;

}