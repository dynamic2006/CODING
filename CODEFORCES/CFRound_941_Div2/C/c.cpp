#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.in", "r", stdin);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        set<int> a;
        for(int i=0; i<n; i++){
            int num; cin >> num;
            a.insert(num);
        }
        
        auto ptr = a.begin();
        int count = 1;
        bool aliceTurn = true;
        bool aliceWins = false;
        if(a.size() % 2 == 1) aliceWins = true;
        while(ptr != a.end()){
            if(*ptr != count){
                if(aliceTurn) aliceWins = true;
                else aliceWins = false;
                break;
            }
            count++;
            aliceTurn = !aliceTurn;
            ptr = next(ptr);
        }
        
        if(aliceWins) cout << "Alice" << endl;
        else cout << "Bob" << endl;
    }
}