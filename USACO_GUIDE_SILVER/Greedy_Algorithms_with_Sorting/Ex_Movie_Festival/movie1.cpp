#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("movie.in" , "r" , stdin);

    int n; cin >> n;
    vector<pair<int, int>> movies(n);
    for(int i=0; i<n; i++){
        cin >> movies[i].second >> movies[i].first;
    }
    sort(movies.begin() , movies.end());

    int ans = 0;
    int lastEndTime = -1;
    for(auto movie : movies){
        if(movie.second >= lastEndTime){
            lastEndTime = movie.first;
            ans++;
        }
    }
    cout << ans << endl;
}