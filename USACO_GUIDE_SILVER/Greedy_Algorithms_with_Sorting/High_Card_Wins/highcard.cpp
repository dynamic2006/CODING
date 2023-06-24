#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("highcard.in" , "r" , stdin);
    freopen("highcard.out" , "w" , stdout);

    int n; cin >> n;
    set<int> bessieHand;
    vector<int> elsieHand;
    for(int i=0; i<2*n; i++){
        bessieHand.insert(i+1);
    }
    int card;
    for(int i=0; i<n; i++){
        cin >> card;
        elsieHand.push_back(card);
        bessieHand.erase(card);
    }

    int wins = 0;
    for(int i=0; i<n; i++){
        card = elsieHand[i];
        auto it = bessieHand.upper_bound(card);
        if(it != bessieHand.end()){
            bessieHand.erase(it);
            wins++;
        }
    }

    cout << wins << endl;
}