#include <bits/stdc++.h>
using namespace std;

struct Card{
    string position;
    int strength;
};

bool cmp(Card& a, Card& b){
    //if same position, put lower strength card first
    if(a.position == b.position){
        return a.strength < b.strength;
    }
    //put all attack cards before defense cards
    if(a.position == "ATK" && b.position == "DEF"){
        return true;
    }
    return false;
}

int n, m;
vector<Card> jiroCards;
multiset<int> cielCards;

int main(){
    //freopen("ciel.in" , "r" , stdin);
    int cielCard; cin >> n >> m;
    jiroCards.resize(n);
    for(int i=0; i<n; i++){
        cin >> jiroCards[i].position >> jiroCards[i].strength;
    }
    for(int i=0; i<m; i++){
        cin >> cielCard; cielCards.insert(cielCard);
    }

    sort(jiroCards.begin() , jiroCards.end() , cmp);

    //What if there is a jiroCard that is DEF and has large strength?
    //better to waste a high value cielCard on this jiroCard and deal small direct dmg later? (2)
    //or should we not used all cielCards but use high value cielCard on atk jiroCard instead? (1)
    //to deal with this problem, we have TWO greedy scenarios

    //first method (1)
    //pair largest available cielCard with smallest attack jiroCard
    //all cielCards are NOT used

    long long totalDamageA = 0;

    vector<Card>::iterator jiroCard = jiroCards.begin();
    multiset<int>::iterator curCard = cielCards.end();
    while(curCard != cielCards.begin() && jiroCard != jiroCards.end()){
        curCard--;
        if(jiroCard->position == "DEF" || jiroCard->strength > *curCard){
            break;
        }
        totalDamageA += *curCard - jiroCard->strength;
        jiroCard++;
    }

    //second method (2)
    //use ALL possible to use cielCards
    //go BACKWARDS thru jiroCards to deal with DEF cards first
    //for each jiroCard find smallest cielCard greater than jiroCard (or equal to for ATK jiro)

    long long totalDamageB = 0;
    bool cleared = true;

    while(!jiroCards.empty() && !cielCards.empty()){
        if(jiroCards.rbegin()->position == "DEF"){
            curCard = cielCards.upper_bound(jiroCards.rbegin()->strength);
            if(curCard != cielCards.end()){
                cielCards.erase(curCard);
            }
            else{
                cleared = false;
            }
        }
        else if(jiroCards.rbegin()->position == "ATK"){
            curCard = cielCards.lower_bound(jiroCards.rbegin()->strength);
            if(curCard != cielCards.end()){
                totalDamageB += *curCard - jiroCards.rbegin()->strength;
                cielCards.erase(curCard);
            }
            else{
                cleared = false;
            }
        }
        jiroCards.pop_back();
    }

    if(cleared){
        for(auto x : cielCards){
            totalDamageB += x;
        }
    }

    cout << max(totalDamageA , totalDamageB) << endl;



}

// //pair each of ciel's cards from highest to lowest
//     //with each of jiro's cards from lowest to highest
//     //break if ciel's card cannot defeat cur jiro card
//     //FIRST kill off attack cards

//     long long totalDamage = 0;

//     int i=0;
//     for(; i<min(n , m); i++){
//         if(cielCards[m-1-i] <= jiroCards[i].strength && jiroCards[i].position == "DEF") break;
//         if(cielCardsi] < jiroCards[i].strength && jiroCards[i].position == "ATK") break;
//         if(jiroCards[i].position == "DEF") continue;
//         totalDamage += cielCards[i] - jiroCards[i].strength;
//     }
//     if(i == n){
//         while(i < m){
//             totalDamage += cielCards[i];
//             i++;
//         }
//     }

//     cout << totalDamage << endl;