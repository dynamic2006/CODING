#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("lemonade.in" , "r" , stdin);
    freopen("lemonade.out" , "w" , stdout);

    int n; cin >> n;
    vector<int> waitingTimes(n);
    for(int i=0; i<n; i++){
        cin >> waitingTimes[i];
    }
    sort(waitingTimes.begin() , waitingTimes.end());

    int totalCows = 0;
    vector<int>::iterator curCow = waitingTimes.end();
    while(curCow != waitingTimes.begin()){
        if(*prev(curCow) >= totalCows){
            totalCows++; curCow--;
        }
        else break;
    }

    cout << totalCows << endl;
}