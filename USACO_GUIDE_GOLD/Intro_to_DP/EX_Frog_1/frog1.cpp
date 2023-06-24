#include <bits/stdc++.h>
using namespace std;

int main(){

    //freopen("frog1.in" , "r" , stdin);

    int n; cin >> n;
    vector<long long> heights(n);

    for(int i=0; i<n; i++){
        cin >> heights[i];
    }

    vector<long long> costs(n);
    costs[0] = 0;
    costs[1] = abs(heights[1] - heights[0]);
    for(int i=2; i<n; i++){
        costs[i] = min(costs[i-1] + abs(heights[i] - heights[i-1]) , costs[i-2] + abs(heights[i] - heights[i-2]));
    }

    cout << costs[n-1] << endl;
    return 0;

}