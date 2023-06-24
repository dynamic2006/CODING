#include <bits/stdc++.h>
using namespace std;

//a function expression 
//return type of function is bool , parameter is int ? - check this later
int binarySearch(int lo , int hi , function<bool(int)> f){
    lo--;
    while(lo < hi){
        int mid = lo + (hi - lo + 1)/2;
        //if the median can be this value of mid, make the lower bound mid
        //all values below mid work
        if (f(mid)){
            lo = mid;
        }
        //otherwise, make the upper bound mid-1
        //all values above mid DONT work
        else {
            hi = mid - 1;
        }
    }
    return lo;
}

int main(){
    //freopen("maxmed.in" , "r" , stdin);
    
    int n, k; cin >> n >> k;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    sort(arr.begin() , arr.end());

    //mid is passed as x in the binarySearch function
    //starts with lo = 1, hi = 2e9 and binarySearches to largest possible median
    cout << binarySearch(1 , 2e9 , [&](int x){
        long long operations = 0;
        //starts at the middle element and looks at each ele after
        //decides if an operation must be used to increment this ele to get median x
        for(int i = (n-1)/2; i < n; i++){
            operations += max(0 , x - arr[i]);
        }
        //checks if the operations doesn't exceed the max operations
        return operations <= k;
    }) << endl;

}

//UNFINISHED