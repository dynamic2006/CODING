#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("movie.in" , "r" , stdin);

    int n, k; cin >> n >> k;
    vector<pair<int , int>> movies(n);
    multiset<int> finishTimes;
    for(int i=0; i<n; i++){
        //want to sort by finishing times
        //so cin the finishing time as "first"
        cin >> movies[i].second >> movies[i].first;
        if(i<k) finishTimes.insert(0);
    }
    sort(movies.begin() , movies.end());

    int totalMovies = 0;
    for(int curMovie = 0; curMovie < n; curMovie++){

        auto it = finishTimes.upper_bound(movies[curMovie].second);

        //if someone finished watching their movies they can watch the next one
        if(it != finishTimes.begin()){
            finishTimes.erase(prev(it));
            finishTimes.insert(movies[curMovie].first);
            totalMovies++;
        }

        //otherwise move on to the next movie
    }

    cout << totalMovies << endl;


}