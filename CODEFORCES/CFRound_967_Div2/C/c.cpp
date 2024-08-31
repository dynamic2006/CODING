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
        int n; cin >> n;
        vector<int> edges;
        for(int a=2; a<=n; a++){
            int x = 1;
            int prevx = x;
            while(x != a){
                cout << "? " << a << " " << x << endl;
                prevx = x;
                cin >> x;
            }
            edges.push_back(prevx);
            edges.push_back(a);
        }
        cout << "! ";
        for(auto x : edges) cout << x << " ";
        cout << endl;
    }
}

//trick is to use binary search and fix root as 1