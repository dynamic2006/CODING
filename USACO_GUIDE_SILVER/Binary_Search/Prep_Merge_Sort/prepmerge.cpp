#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> mergeArrs;

void binaryInsert(int num){
    int lo = 0, hi = mergeArrs.size();
    while(lo < hi){
        int mid = lo + (hi - lo)/2;
        if(*mergeArrs[mid].rbegin() < num) hi = mid;
        else lo = mid + 1;
    }
    if(lo == mergeArrs.size()) mergeArrs.push_back({num});
    else mergeArrs[lo].push_back(num);
}

int main(){
    //freopen("prepmerge.in" , "r" , stdin);

    int x; cin >> n;
    for(int i=0; i<n; i++){
        cin >> x;
        binaryInsert(x);
    }

    for(auto arr : mergeArrs){
        for(auto num : arr){
            cout << num << " ";
        }
        cout << endl;
    }

}

/*
 * NOTES
 * naively simulating the process would take O(n^2) time at worst, which is too long
 * so we should see if we can generate all arrays with only one pass through for efficiency
 * thinking about this process, we think about a greedy way to decided which mergeArr to insert the ith element into
 * to simulate the process correctly, we place the ith element into the first mergeArr where it is greater than the last element of this mergeArr
 * 
 * KEY IDEA : note that all existing mergeArrs have the last (largest) elements in strictly decreasing order
 * 
 * the key idea can be proved by thinking about the contradiction
 * if an increase happened at some point, it would have been placed into the previous mergeArr by our greedy alg
 * so there can be NO increases going down the mergeArrs
 * Now just use binarySearch to find the optimal mergeArr to place the ith element into
 * 
 */