#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("cardgame.in" , "r" , stdin);
    freopen("cardgame.out" , "w" , stdout);

    int n; cin >> n;
    set<int> bessieHand;
    vector<int> elsieFirstHalf(n/2) , elsieSecondHalf(n/2);
    for(int i=0; i<2*n; i++){
        bessieHand.insert(i+1);
    }
    for(int i=0; i<n/2; i++){
        cin >> elsieFirstHalf[i];
        bessieHand.erase(elsieFirstHalf[i]);
    }
    for(int i=0; i<n/2; i++){
        cin >> elsieSecondHalf[i];
        bessieHand.erase(elsieSecondHalf[i]);
    }

    sort(elsieFirstHalf.begin() , elsieFirstHalf.end() , [](const int a, const int b){return a > b;});
    sort(elsieSecondHalf.begin() , elsieSecondHalf.end());

    int points = 0;
    for(int i=0; i<n/2; i++){
        if(*bessieHand.begin() < elsieSecondHalf[i]){
            bessieHand.erase(bessieHand.begin()); points++;
        }
    }
    set<int>::iterator it = bessieHand.begin();
    for(int i=0; i<n/2; i++){
        it = bessieHand.upper_bound(elsieFirstHalf[i]);
        if(it != bessieHand.end()){
            bessieHand.erase(it); points++;
        }
    }

    cout << points << endl;

}