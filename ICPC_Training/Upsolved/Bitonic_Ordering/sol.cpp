#include <bits/stdc++.h>
using namespace std;

#include <bits/extc++.h>
using namespace __gnu_pbds;
template<class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.in", "r", stdin);

    int n; cin >> n;
    vector<int> cards(n);
    for(int i=0; i<n; i++) cin >> cards[i];

    map<int, int> comp;
    for(int i=0; i<cards.size(); i++) comp[cards[i]] = i;

    Tree<int> t;
    for(int i=0; i<cards.size(); i++) t.insert(i);
    
    sort(cards.begin(), cards.end());

    int cardsLeft = n;
    ll moves = 0;
    for(int i=0; i<n; i++){
        int rank = t.order_of_key(comp[cards[i]]);
        cardsLeft--; t.erase(comp[cards[i]]);
        moves += min(rank, cardsLeft-rank);
    }
    cout << moves << endl;

    //greedy approach -- move smallest # card least # of moves to either end
    //note this doesn't affect the next smallest card
    //since if it goes to same end, no change, if it goes to other end
    //it actually helps the card to be switched with current card
    //use ord stat tree to track compressed values of cards / order of cards
}