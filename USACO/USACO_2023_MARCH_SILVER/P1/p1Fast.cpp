#include <bits/stdc++.h>
using namespace std;

vector<long long> indices, milks, suffixSum;
long long ans = 0;

//BUILD A SUFFIX SUM!!! this makes the queries each run in logn time instead of n!

void solve(){
    long long cow, newMilk; cin >> cow >> newMilk;
    auto idx = milks.at; //latest occ of milk we want to change;
    //cout << endl;
    sort(tempMilk.begin() , tempMilk.end());
    long long ans = 0;
    for(long long i=1; i<tempMilk.size(); i++){
        //cout << tempMilk[i]*i << endl;
        ans += tempMilk[i] * i;
    }
    cout << ans << endl;
}

int main(){
    freopen("p1.in" , "r" , stdin);

    long long n; cin >> n;
    suffixSum.resize(n+1); suffixSum[n] = 0;
    indices.push_back(0);
    milks.push_back(0);
    for(long long i=1; i<=n; i++){
        long long m; cin >> m;
        milks.push_back(m);
        indices.push_back(m);
    }

    //fill suffixSum
    //suffixSum[i] gives sum of all milks strictly after cow i
    for(int i=n-1; i>=0; i--){
        suffixSum[i] = suffixSum[i+1] + indices[i+1];
    }
    sort(milks.begin() , milks.end());

    //precalculate best cost
    long long count = 1;
    for(auto x : milks){
        ans += x * count;
        count++;
    }
    cout << ans << endl;
    
    //works so far...

    long long q; cin >> q;

    for(long long i=0; i<q; i++){
        solve();
    }
}