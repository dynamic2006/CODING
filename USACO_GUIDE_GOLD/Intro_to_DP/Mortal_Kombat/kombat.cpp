#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<bool> bosses(n);
    for(int i=0; i<n; i++){
        int boss; cin >> boss;
        bosses[i] = boss;
    }

    vector<int> a(n), b(n);
    b[0] = bosses[0]; a[0] = b[0];
    for(int i=1; i<n; i++){
        //if a plays ith turn
        //b must have played i-1 or i-2 turn
        a[i] = b[i-1];
        if(i>1) a[i] = min(a[i] , b[i-2]);

        //if b plays ith turn
        //a must have played i-1 or i-2 turn
        //a could have also played both i-1 and i-2
        //so b[i] also depends on b[i-3]
        b[i] = b[i-1];
        if(i>1) b[i] = min(b[i], b[i-2]);
        if(i>2) b[i] = min(b[i], b[i-3]);
        b[i] += bosses[i];
    }

    cout << min(a[n-1], b[n-1]) << endl;
    return;
}

int main() {

    //freopen("kombat.in" , "r" , stdin);

    int t; cin >> t;
    while(t--) solve();
    return 0;

}