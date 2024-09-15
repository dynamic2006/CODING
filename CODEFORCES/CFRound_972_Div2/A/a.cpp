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
        vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        int occ = n/5;
        int rem = n%5;

        
        int counter = 0;
        string s = "";
        for(int i=0; i<min(n, 5); i++){
            for(int j=0; j<occ; j++) s += vowels[i];
            if(i<rem) s += vowels[i];
        }
        cout << s << endl;
    }
}