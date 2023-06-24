#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("taming.in" , "r" , stdin);
    freopen("taming.out" , "w" , stdout);

    int n; cin >> n;
    vector<int> entries(n);
    for(int i=0; i<n; i++){
        cin >> entries[i];
        if(entries[i] > 0){
            int cur = i-1 , fixes = entries[i]-1;
            while(fixes > -1 && cur > -1){
                if(entries[cur] != fixes && entries[cur] != -1){
                    cout << -1 << endl; return 0;
                }
                entries[cur] = fixes;
                cur--; fixes--;
            }
        }
    }
    if(entries[0] > 0){cout << -1 << endl; return 0;}

    //the number of zeros is the days where there MUST have been a breakout
    //the number of -1's are the days where there MIGHT have been a breakout

    entries[0] = 0;

    int maxi = 0 , mini = 0;
    for(int i=0; i<n; i++){
        if(entries[i] == 0){
            mini++; maxi++;
        }
        else if(entries[i] == -1) maxi++;
    }

    cout << mini << " " << maxi << endl; return 0;

}