#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("p1.in" , "r" , stdin);

    long long n; cin >> n;
    map<long long, long long> cows;
    vector<int> milks;
    for(long long i=1; i<=n; i++){
        cin >> cows[i];
        milks[i] = cows[i];
    }

    multiset<int> test;
    test.lower_bound(0);

    long long q; cin >> q;

    for(long long i=0; i<q; i++){
        int cow, newMilk; cin >> cow >> newMilk;
    }

    for(auto x : cows){
        cout << x.first << " " << x.second << endl;
    }
    return 0;
}