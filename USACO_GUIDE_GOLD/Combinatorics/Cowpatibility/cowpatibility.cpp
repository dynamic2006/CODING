#include <bits/stdc++.h>
using namespace std;

map<vector<long long> , long long> subsetLikes;
long long PIE[6] = {0, 1, -1, 1, -1, 1};

int main() {

    freopen("cowpatibility.in" , "r" , stdin);
    freopen("cowpatibility.out" , "w" , stdout);

    long long n; cin >> n;
    for (long long i=0; i<n; i++){

        vector<long long> cowFlavors(5);
        vector<vector<long long>> cowSubsets;

        for(int j=0; j<5; j++) cin >> cowFlavors[j];
        sort(cowFlavors.begin() , cowFlavors.end());

        for (long long j=0; j<5; j++){
            for (long long k = cowSubsets.size() - 1; k>=0; k--){
                vector<long long> newSubset = cowSubsets[k];
                newSubset.push_back(cowFlavors[j]);
                cowSubsets.push_back(newSubset);
                subsetLikes[newSubset]++;
            }
            cowSubsets.push_back({cowFlavors[j]});
            subsetLikes[{cowFlavors[j]}]++;
        }
    
    }

    long long complement = 0;
    for(auto subset : subsetLikes){
        
        long long pairs = (subset.second) * (subset.second - 1) / 2;
        complement += (pairs) * (PIE[subset.first.size()]);

    }

    long long total = (n)*(n-1) / 2;
    cout << total - complement << endl;
    return 0;

}

//NOTES
//make sure to SORT cowFlavors before forming subsets
//otherwise, for example, {1,2,3} and {3,1,2} are counted
//as different subsets even though they are the same

//also, this solution TLEs on test cases 9 and 10
//see official solution for a faster way