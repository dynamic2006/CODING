#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.in", "r", stdin);

    int n; cin >> n;
    map<int, int> occs;
    for(int i=0; i<10*n; i++){
        for(int j=0; j<5; j++){
            int num; cin >> num;
            occs[num]++;
        }
    }

    bool sus = false;
    for(auto &x : occs){
        if(x.second > 2*n){
            cout << x.first << " ";
            sus = true;
        }
    }
    if(!sus) cout << -1 << endl;
    else cout << endl;

}