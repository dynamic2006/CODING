#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("static_range_sum.in" , "r" , stdin);

    int n, q, num; cin >> n >> q;
    //to hold the total orefix sums -- saves time for answering the queries
    vector<long long> prefix_sums(n+1);
    prefix_sums[0] = 0; //anchoring the first prefix sum at zero
    for(int i=1; i<=n; i++){
        cin >> num;
        prefix_sums[i] = prefix_sums[i-1] + num; //filling the prefix_sums vector
    }

    int a, b;
    for(int i=0; i<q; i++){
        cin >> a >> b;
        cout << prefix_sums[b] - prefix_sums[a] << endl; //use prefix sum vector to answer each query
    }
}