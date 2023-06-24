#include <bits/stdc++.h>
using namespace std;

void solve(vector<long long> tempMilk){
    long long cow, newMilk; cin >> cow >> newMilk;
    tempMilk[cow] = newMilk;
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
    //freopen("p1.in" , "r" , stdin);

    long long n; cin >> n;
    vector<long long> milk(n+1); milk[0] = 0;
    for(long long i=1; i<=n; i++){
        cin >> milk[i];
    }

    long long q; cin >> q;

    for(long long i=0; i<q; i++){
        solve(milk);
    }
}