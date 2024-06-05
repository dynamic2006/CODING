#include <bits/stdc++.h>
using namespace std;

long long n, q;
vector<long long> cowsOld;

int main()
{
    //freopen("p1.in" , "r", stdin);
    
    cin >> n;
    for(long long i=0; i<n; i++){
        long long c; cin >> c;
        cowsOld.push_back(c);
    }
    vector<long long> cowsNew = cowsOld;
    sort(cowsNew.begin() , cowsNew.end());

    vector<long long> suffix(n+1); suffix[n] = 0;
    long long ans = 0;
    for(long long i=n-1; i>=0; i--){
        suffix[i] = cowsNew[i] + suffix[i+1];
        ans += suffix[i];
    }

    long long tempAns = ans;

    cin >> q;
    for(long long k=0; k<q; k++){
        //use cowsOld to find cow whose milk produce changed
        //locate that cow's new spot and old spot with binary seach
        long long a, b; cin >> a >> b; a--;
        long long oldSpot = lower_bound(cowsNew.begin(), cowsNew.end(), cowsOld[a]) - cowsNew.begin();
        long long newSpot = lower_bound(cowsNew.begin(), cowsNew.end(), b) - cowsNew.begin();
        long long rangeCount = 0;
        if(oldSpot < newSpot){
            newSpot--;
            rangeCount = suffix[oldSpot+1] - suffix[newSpot+1];
            tempAns -= rangeCount;
            tempAns -= (oldSpot+1)*(cowsOld[a]);
            tempAns += (newSpot+1)*(b);
        }
        else{
            rangeCount = suffix[newSpot] - suffix[oldSpot];
            tempAns += rangeCount;
            tempAns -= (oldSpot+1)*(cowsOld[a]);
            tempAns += (newSpot+1)*(b);
        }

        cout << tempAns << endl;
        tempAns = ans;
    }

    return 0;



}