#include <bits/stdc++.h>
using namespace std;

const double SIGFIGS = 0.001;

int n;
vector<int> machines;

bool valid(double minAvg){
    //subtract minAvg from each machine
    //and make a prefix sum array for the machines

    vector<double> prefixSums(n); prefixSums[0] = machines[0] - minAvg;
    double minSum = machines[0] - minAvg, maxSum = machines[1] - minAvg;
    for(int i=1; i<n; i++){
        prefixSums[i] = prefixSums[i-1] + (machines[i] - minAvg);
        if(i == n-1) continue;
        maxSum = max(maxSum , prefixSums[i] - minSum);
        minSum = min(minSum , prefixSums[i]);
    }

    //check if the remaining machines will
    //produce atleast minAvg average amt of milk
    if(prefixSums[n-1] - maxSum > 0) return false;
    //cout << minSum << " " << maxSum << endl;
    return true;
}

double binarySearch(double lo , double hi){
    hi += SIGFIGS;
    while(hi - lo > SIGFIGS){
        double mid = lo + (hi - lo)/2;
        if(valid(mid)) hi = mid;
        else lo = mid + SIGFIGS;
    }
    //cout << hi << " " << lo << endl;
    return lo;
}

int main(){

    freopen("sabotage.in" , "r" , stdin);
    freopen("sabotage.out" , "w" , stdout);

    cin >> n;
    for(int i=0; i<n; i++){
        int milk; cin >> milk;
        machines.push_back(milk);
    }

    //DO NOT SORT since it's a subarray-ish problem
    //worst (best?) case scenario: 10,000 | 1 | 10,000
    //so we should make the hi = 1e5 + 1, and lo = 0

    double ans = binarySearch(0 , 1e5 + 1);
    int q = (int) ans; // truncate decimal part
    cout << q << ".";
    for(int i=0; i<3; i++){
        ans *= 10;
        cout << (int)ans % 10;
    }
    cout << endl;
    return 0;

}