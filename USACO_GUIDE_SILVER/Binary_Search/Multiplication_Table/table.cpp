#include <bits/stdc++.h>
using namespace std;

long long n;

bool inUpperHalf(long long num){
    long long countLessThan = 0;
    for(long long i=1; i<=n; i++){
        countLessThan += min(num/i , n);
        if(countLessThan > (n*n)/2) return true;
    }
    return false;
}

//try to minimize
//since for validity we already make sure it is in the upper half
long long binarySearch(long long lo , long long hi){
    hi++;
    while(lo < hi){
        long long mid = lo + (hi - lo)/2;
        if(inUpperHalf(mid)){
            hi = mid;
        }
        else{
            lo = mid + 1;
        }
    }
    return lo;
}

int main(){
    freopen("table.in" , "r" , stdin);

    cin >> n;

    cout << binarySearch(1 , n*n) << endl;
}