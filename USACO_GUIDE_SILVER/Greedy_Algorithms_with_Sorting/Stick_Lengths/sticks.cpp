#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("sticks.in" , "r" , stdin);

    int n; cin >> n;
    long long total = 0;
    vector<int> sticks(n);
    for(int i=0; i<n; i++){
        cin >> sticks[i];
        total += sticks[i];
    }
    sort(sticks.begin() , sticks.end());

    long long target = sticks[n/2]; //the target value is the median of the stick lengths
    long long cost = 0;
    for(int i=0; i<n; i++){
        cost += abs(target - sticks[i]);
    }

    cout << cost << endl;
}