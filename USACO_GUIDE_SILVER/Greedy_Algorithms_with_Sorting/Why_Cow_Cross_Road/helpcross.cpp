#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("helpcross.in" , "r" , stdin);
    freopen("helpcross.out" , "w" , stdout);

    int c , n , chicken; cin >> c >> n;
    multiset<int> chickenTimes;
    for(int i=0; i<c; i++){
        cin >> chicken;
        chickenTimes.insert(chicken);
    }
    vector<pair<int , int>> cowTimeRanges(n);
    for(int i=0; i<n; i++){
        //take END time as second value for sorting by end times later
        cin >> cowTimeRanges[i].second >> cowTimeRanges[i].first;
    }

    sort(cowTimeRanges.begin() , cowTimeRanges.end());

    int totalPairs = 0;

    vector<pair<int , int>>::iterator curCow = cowTimeRanges.begin();
    multiset<int>::iterator curChicken = chickenTimes.begin();

    for(int i=0; i<n; i++){
        curChicken = chickenTimes.lower_bound(cowTimeRanges[i].second); //find first chicken that comes at or after current cow's start time
        if(curChicken != chickenTimes.end() && *curChicken <= cowTimeRanges[i].first){
            //if the chicken also comes before the current cow's end time
            //note that by greedy we should take the first such chicken
            totalPairs++;
            chickenTimes.erase(curChicken); //erase this chicken
        }
        //otherwise moove on to next cow
    }

    cout << totalPairs << endl;


}