#include <bits/stdc++.h>
using namespace std;

string bitString; int n;
set<int> changeIdxs; //useful since many changes are made, and we use the find() function
priority_queue<int> contRanges; //useful since need the largest range (last element)
int rangeLengthOccurences[200010];

void modify(int index){
    if(index == 0 || index == bitString.size()) return; //no changes
    
    set<int>::iterator it = changeIdxs.find(index);

    //if the index is currently in the changeIdxs set, then REMOVE it
    if(it != changeIdxs.end()){
        rangeLengthOccurences[*(it) - *prev(it)]--;
        rangeLengthOccurences[*next(it) - *(it)]--;
        rangeLengthOccurences[*next(it) - *prev(it)]++;
        contRanges.push(*next(it) - *prev(it));
        changeIdxs.erase(it);
    }
    //otherwise index is NOT currently in the changeIdxs set, so ADD it in
    else{
        it = changeIdxs.insert(index).first;
        rangeLengthOccurences[*next(it) - *prev(it)]--;
        rangeLengthOccurences[*next(it) - *(it)]++;
        rangeLengthOccurences[*(it) - *prev(it)]++;
        contRanges.push(*next(it) - *(it));
        contRanges.push(*(it) - *prev(it));
    }
}

int main(){
    //freopen("bits.in" , "r" , stdin);

    cin >> bitString >> n;

    changeIdxs.insert(0);
    set<int>::iterator it = changeIdxs.begin();
    for(int i=1; i<bitString.size(); i++){
        it = changeIdxs.end();
        if(bitString[i] != bitString[i-1]){
            rangeLengthOccurences[i - *prev(it)]++;
            contRanges.push(i - *prev(it));
            changeIdxs.insert(i);
        }
    }
    rangeLengthOccurences[bitString.size() - *prev(changeIdxs.end())]++;
    contRanges.push(bitString.size() - *prev(changeIdxs.end()));
    changeIdxs.insert(bitString.size());

    for(int i=0; i<n; i++){
        int bit; cin >> bit; bit--; //make it 0-indexed
        modify(bit); modify(bit+1);
        while(rangeLengthOccurences[contRanges.top()] == 0){contRanges.pop();}
        cout << contRanges.top() << " ";
    }
}

/*
 * NOTES
 * this problem is VERY SIMILAR to the problem "Traffic Lights"
 * instead of the lights, we have bits (1 if there is a "light" there)
 * and instead of counting gaps, we count continuous ranges (priority queue used instead of multiset for efficiency)
 */