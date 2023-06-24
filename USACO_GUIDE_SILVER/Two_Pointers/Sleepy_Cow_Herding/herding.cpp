#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("herding.in" , "r" , stdin);
    freopen("herding.out" , "w" , stdout);

    int n; cin >> n;
    vector<int> positions(n);
    for(int i=0; i<n; i++){
        cin >> positions[i];
    }
    sort(positions.begin() , positions.end());

    //special cases where n-1 cows already consecutive
    int minTotalMoves = n+1 , maxTotalMoves = 0 , maxCowCount = -1;
    if(positions[n-2] - positions[0] + 1 == n-1 && positions[n-1] - positions[n-1] - 1 > 1) minTotalMoves = 2;
    else if(positions[n-1] - positions[1] + 1 == n-1 && positions[1] - positions[0] - 1 > 1) minTotalMoves = 2;
    else{
        int right = 0;
        for(int left = 0; left < n; left++){
            while(right < n && positions[right] - positions[left] <= n) right++;
            maxCowCount = max(maxCowCount , right - left); //right excluded, left included
        }
        minTotalMoves = n - maxCowCount; //number of spaces in final block, this number of cows must be mooved
    }
    maxTotalMoves = max(positions[n-1] - positions[1] , positions[n-2] - positions[0]) - (n-2); //either piggyback with two cows @end or @start

    cout << minTotalMoves << endl << maxTotalMoves << endl;


}