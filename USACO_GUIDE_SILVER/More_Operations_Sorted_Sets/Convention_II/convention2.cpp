#include <bits/stdc++.h>
using namespace std;

struct Cow{
    int seniority, arrivalTime, duration;
};

bool cmp_arrival(const Cow& a, const Cow& b){
    return a.arrivalTime < b.arrivalTime;
}

bool cmp_seniority(const Cow& a, const Cow& b){
    return a.seniority > b.seniority;
}

int main(){
    freopen("convention2.in" , "r" , stdin);
    freopen("convention2.out" , "w" , stdout);

    int n; cin >> n;
    vector<Cow> cows(n);
    for(int i=0; i<n; i++){
        cin >> cows[i].arrivalTime >> cows[i].duration;
        cows[i].seniority = i;
    }
    sort(cows.begin() , cows.end() , cmp_arrival);

    int cur = 0; //index of current cow
    int freePastureAtTime = 0;
    int max_wait = -1;

    set<Cow , bool(*)(const Cow& , const Cow&)> waitingLine(cmp_seniority); //last cow has HIGHEST seniority
    while(!waitingLine.empty() || cur < n){
        //waiting line HAS cows AND arrivalTime of cur cow doesn't change freePastureAtTime
        if(!waitingLine.empty() && cur < n && cows[cur].arrivalTime <= freePastureAtTime){
            waitingLine.insert(cows[cur]);
        }

        //waiting line HAS cow(s) BUT arrivalTime of cur cow changes freePastureAtTime
        else if(!waitingLine.empty()){
            max_wait = max(max_wait , freePastureAtTime - prev(waitingLine.end())->arrivalTime);
            freePastureAtTime += prev(waitingLine.end())->duration;
            waitingLine.erase(prev(waitingLine.end()));
            if(cur >= n)continue;
            if(freePastureAtTime >= cows[cur].arrivalTime) waitingLine.insert(cows[cur]);
            else continue;
        }

        //waiting line DOES NOT have cows BUT cow should be placed in line
        else if(cows[cur].arrivalTime <= freePastureAtTime){
            waitingLine.insert(cows[cur]); continue;
        }

        //waiting line DOES NOT have cows AND cow can be put in pasture
        else{
            freePastureAtTime = cows[cur].arrivalTime + cows[cur].duration;
        }

        cur++;
    }

    cout << max_wait << endl;

}