#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("input.in", "r", stdin);

    int n; cin >> n;
    vector<int> cards(n);
    for(int i=0; i<n; i++) cin >> cards[i];

    vector<int> prefixMinSwaps(n), suffixMinSwaps(n);

    prefixMinSwaps[0] = 0;
    set<int> curSortedPrefix; curSortedPrefix.insert(cards[0]);
    for(int i=1; i<n; i++){
        auto it = curSortedPrefix.lower_bound(cards[i]);
        if(it == curSortedPrefix.end()){
            curSortedPrefix.insert(cards[i]);
            continue;
        }
        else{
            int addSwaps = distance(curSortedPrefix.end(), it);
            prefixMinSwaps[i] = prefixMinSwaps[i-1] + addSwaps;
            curSortedPrefix.insert(cards[i]);
        }
    }

    suffixMinSwaps[n-1] = 0;
    set<int> curSortedSuffix; curSortedSuffix.insert(cards[0]);
    for(int i=1; i<n; i++){
        auto it = curSortedSuffix.lower_bound(cards[i]);
        if(it == curSortedSuffix.end()){
            curSortedPrefix.insert(cards[i]);
            continue;
        }
        else{
            int addSwaps = distance(curSortedPrefix.end(), it);
            prefixMinSwaps[i] = prefixMinSwaps[i-1] + addSwaps;
            curSortedPrefix.insert(cards[i]);
        }
    }
}

//ideas
//binary search on the min swaps
//swaps can be concatenated to make a range
//maybe make dp for each potential cutoff point
