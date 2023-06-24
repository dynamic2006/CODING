#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("stick.in" , "r" , stdin);
    int stickLength, totalParts, curStick;
    cin >> stickLength >> totalParts;
    multiset<int> stickParts;
    for(int i=0; i<totalParts; i++){
        cin >> curStick;
        stickParts.insert(curStick);
    }

    long long totalCost = 0;
    while(stickParts.size() > 1){
        auto it = stickParts.begin();
        int sum = *(it) + *next(it);
        totalCost += sum;
        stickParts.erase(next(it));
        stickParts.erase(it);
        stickParts.insert(sum);
    }

    cout << totalCost << endl;
}

/*
 * NOTES
 * we use the Huffman Coding Algorithm
 * which states that to minimize the total cost
 * we should work backwards
 * combining the two smallest stick lengths into a stick of length sum
 * then adding sum to our totalCost
 * and repeating the process until only one stick is left
 * note that this makes logical sense from a greedy perspective
 * since if the cost for each individual division is minimized
 * then the overall cost should also be minimized for this procedure
 */