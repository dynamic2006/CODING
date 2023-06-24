#include <bits/stdc++.h>
using namespace std;

int main(){

    freopen("diamond.in" , "r" , stdin);
    freopen("diamond.out" , "w" , stdout);

    int n, k; cin >> n >> k;

    //cin all diamonds and sort them
    //for the smallest diamond in the first case
    //you can construct the maximum case size
    //and also find the bext possible second case to pair with

    vector<int> diamonds(n);
    for(int i=0; i<n; i++) cin >> diamonds[i];
    sort(diamonds.begin() , diamonds.end());

    //TWO POINTERS
    vector<int> firstCaseSizes(n);
    int l = 0, r = 0;
    while(l < n){
        while(r < n && diamonds[r] - k <= diamonds[l]) r++;
        firstCaseSizes[l] = r-l; l++;
    }

    //MAX SUFFIX ARRAY
    //maximum case size after and including the start diamond i
    vector<int> optimalSecondCaseSizes(n+1); optimalSecondCaseSizes[n] = 0;
    for(int i=n-1; i>=0; i--){
        optimalSecondCaseSizes[i] = max(optimalSecondCaseSizes[i+1] , firstCaseSizes[i]);
    }

    //answer the problem
    //note that we don't want to accidentally repeat diamonds in both cases
    int total = 0;
    for(int i=0; i<n; i++){
        total = max(total , firstCaseSizes[i] + optimalSecondCaseSizes[i + firstCaseSizes[i]]);
    }
    cout << total << endl;
    return 0;

}