#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("input.in", "r", stdin);
}

//ideas
//unify updates with same range min value
//if two updates with same range min value are disjoint, false
//now you have unique min value ranges
//might have to sort ranges in descending order min values
//keep diff table with ranges start and end values
//if conflict with same start/end value, keep larger min value

//now diff table is filled
//keep priority queue with values seen so far over diff table iteration
//in prefix max min table, insert pq.top() value
//at end, to check, for each number either start or end MUST be that number

//count and keep occs of each number in prefix table
//make suffix sum of occs from n->1
//iterate each num k from 1 to n and calculate possibilities for k
//this is just (n-k+1) - (suffixSum[k+1])
//OR, if k occs>0, use the occs value instead