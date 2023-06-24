#include <bits/stdc++.h>
using namespace std;

map<int, int> occs;
int maxGCD = 1;

void factor(int a){
    for(int i=1; i*i <= a; i++){
        if(a % i == 0){
            occs[i]++;
            if(i != a/i) occs[a/i]++;
            if(occs[a/i] >= 2){
                maxGCD = max(maxGCD, a/i);
                return;
            }
            if(occs[i] >= 2) maxGCD = max(maxGCD, i);
        }
    }
}

int main(){

    //freopen("divisors.in" , "r" , stdin);

    int n; cin >> n;
    
    for(int i=0; i<n; i++){
        int x; cin >> x;
        factor(x);
    }

    cout << maxGCD << endl;

}