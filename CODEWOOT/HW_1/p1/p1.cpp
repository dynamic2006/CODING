#include <bits/stdc++.h>
using namespace std;

vector<int> maxHeap;

int parentIdx(int idx){
    return (idx-1)/2;
}

void addVal(int x){

    maxHeap.push_back(x);
    int curIdx = maxHeap.size() - 1; //this is where x is currently

    //swap vals to restore maxHeap
    while(curIdx != 0 && maxHeap[(curIdx - 1)/2] < maxHeap[curIdx]){
        int parentVal = maxHeap[(curIdx - 1)/2];
        maxHeap[(curIdx - 1)/2] = x;
        maxHeap[curIdx] = parentVal;

        curIdx = (curIdx-1)/2;
    }

}

void delMaxVal(){

    //get last element
    int x = maxHeap[maxHeap.size() - 1];
    maxHeap.pop_back();

    //replace x as head
    maxHeap[0] = x;
    int curIdx = 0;
    int tempIdx;

    //propagate x downwards
    //if next level exists, then we can go down
    while(curIdx*2 + 1 < maxHeap.size()){
        //if both children exist, then need to check both
        if(curIdx*2 + 2 < maxHeap.size()){
            tempIdx = curIdx;
            
            if(x < maxHeap[curIdx*2 + 2]) tempIdx = curIdx*2 + 2;
            if(x < maxHeap[curIdx*2 + 1] && maxHeap[curIdx*2 + 1] > maxHeap[curIdx*2 + 2]) tempIdx = curIdx*2 + 1;
            if(curIdx == tempIdx) break;
            
            maxHeap[curIdx] = maxHeap[tempIdx];
            maxHeap[tempIdx] = x;
            curIdx = tempIdx;

        }
        //if just first child exists, check it
        else if(x < maxHeap[curIdx*2 + 1]){
            maxHeap[curIdx] = maxHeap[curIdx*2 + 1];
            maxHeap[curIdx*2 + 1] = x;
            curIdx = curIdx*2 + 1;
        }
        //otherwise no more prop can happen
        else break;
    }


}

int main() {

    //freopen("p1.in" , "r" , stdin);

    int q; cin >> q;

    for(int i=0; i<q; i++){
        
        int x; cin >> x;
        if(x == 0) delMaxVal();
        else addVal(x);

        for(auto k : maxHeap){
            cout << k << " ";
        }
        cout << endl;

    }

    return 0;

}