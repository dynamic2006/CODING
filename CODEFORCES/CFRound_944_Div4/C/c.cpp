#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("c.in", "r", stdin);

    int t; cin >> t;
    while(t--){
        int a, b, c, d; cin >> a >> b >> c >> d;
        vector<int> firstHalf, secondHalf;
        for(int i=min(a,b)+1; i<max(a,b); i++) firstHalf.push_back(i);
        for(int i=max(a,b)+1; i<=12; i++) secondHalf.push_back(i);
        for(int i=1; i<min(a,b); i++) secondHalf.push_back(i);

        bool validC = false, validD = false;
        for(auto &k : firstHalf){
            if(k == c){
                validC = true;
                for(auto &x : secondHalf){
                    if(x == d){
                        validD = true;
                        break;
                    }
                }
                break;
            }
            if(k == d){
                validD = true;
                for(auto &x : secondHalf){
                    if(x == c){
                        validC = true;
                        break;
                    }
                }
                break;
            }
        }

        if(validC && validD) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}