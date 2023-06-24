#include <bits/stdc++.h>
using namespace std;

long long n, t;
vector<long long> machines;

bool valid(long long tMin){
    long long totalProducts = 0;
    for(int i=0; i<n; i++){
        totalProducts += tMin / machines[i];
        if(totalProducts >= t) return true;
    }
    return false;
}

long long binarySearch(long long lo , long long hi){
    hi++;
    while(lo < hi){
        long long mid = lo + (hi - lo)/2;
        if(valid(mid)){
            hi = mid;
        }
        else{
            lo = mid + 1;
        }
    }
    return lo;
}

int main(){
    //freopen("factory.in" , "r" , stdin);

    cin >> n >> t;
    machines.resize(n);
    for(int i=0; i<n; i++){
        cin >> machines[i];
    }

    //note the maximum time it could take
    //when only one (the slowest) machine makes all t products
    cout << binarySearch(1 , t*machines[n-1]) << endl;
}