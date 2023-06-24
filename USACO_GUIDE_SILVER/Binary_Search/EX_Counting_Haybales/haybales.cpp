#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("haybales.in" , "r" , stdin);
    freopen("haybales.out" , "w" , stdout);

    int n, q; cin >> n >> q;
    vector<int> haybaleLocations(n);
    for(int i=0; i<n; i++){
        cin >> haybaleLocations[i];
    }

    sort(haybaleLocations.begin() , haybaleLocations.end());

    int start, finish;
    while(q--){
        cin >> start >> finish;
        cout << upper_bound(haybaleLocations.begin() , haybaleLocations.end() , finish) 
        - lower_bound(haybaleLocations.begin() , haybaleLocations.end() , start) << endl;
    }
}